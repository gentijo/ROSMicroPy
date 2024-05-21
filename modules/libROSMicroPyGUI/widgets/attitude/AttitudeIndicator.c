#define DISPLAY_INDIVIDUAL_LAYERS

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Windows.Forms;

using GraphicsBuffer = Utilities.GraphicsBuffer;
using TickTypes = AttitudeIndicator.TickMark.Tick_Type;

namespace AttitudeIndicator
    {

    // *************************************** class AttitudeIndicator

    public partial class AttitudeIndicator : Control
        {

        const   int     MAXIMUM_CONTROL_WIDTH = 500;
        const   int     MINIMUM_CONTROL_WIDTH = 150;
        const   int     CONTROL_WIDTH_INCREMENT = 50;

        static  Color   LOWER_HEMISPHERE_COLOR = Color.DarkGoldenrod;
        static  Color   LOWER_HEMISPHERE_TOP = Color.Peru;
        static  Color   LOWER_HEMISPHERE_BOTTOM = Color.RosyBrown;

        static  Color   UPPER_HEMISPHERE_COLOR = Color.DeepSkyBlue;
        static  Color   UPPER_HEMISPHERE_TOP = Color.CornflowerBlue;
        static  Color   UPPER_HEMISPHERE_BOTTOM = Color.PaleTurquoise;

        static  Color   CONTROL_BACKGROUND = Color.DimGray;
        static  Color   TICK_MARK_COLOR = Color.White;
        const   float   TICK_MARK_THICKNESS = 1.0F;

        static  Color   INDICATOR_BACKGROUND = Color.Gray;
        static  Color   INDICATOR_FONT_COLOR = Color.WhiteSmoke;

        const   int     DEGREES_IN_CIRCLE = 360;

        const   int     MINIMUM_CONTROL_FONT = 9;
        const   string  FONT_FAMILY = "Microsoft Sans Serif";
        const   int     FONT_SIZE = 10;

        const   decimal INITIAL_PITCH = 0.0M;
        const   decimal MAXIMUM_PITCH = 40.0M;
        const   decimal MINIMUM_PITCH = -40.0M;

        const   decimal INITIAL_ROLL = 0.0M;
        const   decimal MAXIMUM_ROLL = 90.0M;
        const   decimal MINIMUM_ROLL = -90.0M;

        const   int     TICK_MARK_BASE_AT_MAXIMUM = 10;
        const   int     TICK_MARK_HEIGHT_TO_BASE = 2;

        // ******************************************* class variables

        public Dictionary < string, bool > display_layer = 
                                    new Dictionary < string, 
                                                     bool > ( );
        public string [ ]   layers = new string [ ] { "Background",
                                                      "SkyGround",
                                                      "Pitch",
                                                      "TopBottom",
                                                      "Roll",
                                                      "Indicator",
                                                      "Stationary" };

        GraphicsBuffer      background_layer = null;
        Point               control_center;
        decimal             current_pitch = INITIAL_PITCH;
        decimal             current_roll = INITIAL_ROLL;
        int                 control_width = MAXIMUM_CONTROL_WIDTH;
        int                 font_size = FONT_SIZE;
        GraphicsBuffer      indicator_layer = null;
        int                 inner_ring_diameter;
        int                 inner_ring_radius;
        int                 instrument_offset;
        int                 middle_ring_radius;
        int                 orr_div_10;
        double              outer_radius;
        int                 outer_ring_diameter;
        int                 outer_ring_radius;
        GraphicsBuffer      pitch_layer = null;
        bool                revise_attitude_layers = true;
        bool                revise_background_layer = true;
        GraphicsBuffer      roll_layer = null;
        GraphicsBuffer      sky_ground_layer = null;
        GraphicsBuffer      stationary_layer = null;
        int                 tick_mark_base;
        int                 tick_mark_half_base; 
        int                 tick_mark_height;
        List < TickMark >   tick_marks = new List < TickMark > ( );
        GraphicsBuffer      top_bottom_layer = null;

        // ******************************************** memory_cleanup

        void memory_cleanup ( object    sender,
                              EventArgs e )
            {

            if ( background_layer != null )
                {
                background_layer = background_layer.
                                   DeleteGraphicsBuffer ( );
                }

            if ( indicator_layer != null )
                {
                indicator_layer = indicator_layer.
                                  DeleteGraphicsBuffer ( );
                }

            if ( pitch_layer != null )
                {
                pitch_layer = pitch_layer.DeleteGraphicsBuffer ( );
                }

            if ( roll_layer != null )
                {
                roll_layer = roll_layer.DeleteGraphicsBuffer ( );
                }

            if ( sky_ground_layer != null )
                {
                sky_ground_layer = sky_ground_layer.
                                   DeleteGraphicsBuffer ( );
                }

            if ( stationary_layer != null )
                {
                stationary_layer = stationary_layer.
                                   DeleteGraphicsBuffer ( );
                }

            if ( top_bottom_layer != null )
                {
                top_bottom_layer = top_bottom_layer.
                                   DeleteGraphicsBuffer ( );
                }
            }

        // ************************************************* deg_2_rad

        double deg_2_rad ( double degrees )
            {

            return ( Math.PI * ( degrees / 180.0 ) );
            }

        // ***************************************************** round

        // http://en.wikipedia.org/wiki/Rounding

        int round ( double parameter )
            {

            return ( ( int ) ( parameter + 0.5 ) );
            }

        // ***************************************************** round

        // http://en.wikipedia.org/wiki/Rounding

        int round ( float parameter )
            {

            return ( ( int ) ( parameter + 0.5F ) );
            }

        // ***************************************************** round

        // http://en.wikipedia.org/wiki/Rounding

        int round ( decimal parameter )
            {

            return ( ( int ) ( parameter + 0.5M ) );
            }

        // ************************************ revise_geometry_values

        void revise_geometry_values ( )
            {
            int  middle_ring_diameter;
            int  offset;
                                        // instrument circle
            instrument_offset = 
                round ( ( float ) ControlWidth / 20.0F );
                                        // outer marks ring
            offset = round ( 1.5F * ( float ) instrument_offset );
            outer_ring_diameter = ControlWidth - ( 2 * offset );
            outer_ring_radius = outer_ring_diameter / 2;
            orr_div_10 = 
                round ( ( float ) outer_ring_radius / 10.0F );

            outer_radius = ( double ) outer_ring_radius;
                                        // middle marks ring
            offset = round ( 2.0F * ( float ) instrument_offset );
            middle_ring_diameter = ControlWidth - ( 2 * offset );
            middle_ring_radius = middle_ring_diameter / 2;
                                        // inner marks ring
            offset = round ( 2.5F * ( float ) instrument_offset );
            inner_ring_diameter = ControlWidth - ( 2 * offset );
            inner_ring_radius = inner_ring_diameter / 2;
                                        // define tick mark size
            tick_mark_base = ( TICK_MARK_BASE_AT_MAXIMUM * 
                               ControlWidth ) / 
                             MAXIMUM_CONTROL_WIDTH;
            tick_mark_height = TICK_MARK_HEIGHT_TO_BASE * 
                               tick_mark_base;
            tick_mark_half_base = round ( ( float ) tick_mark_base /
                                          2.0F ); 
            }

        // ******************************* generate_tick_mark_geometry

        void generate_tick_mark_geometry ( )
            {
            Point       center;
            int [ ]     tick_mark_degrees = { 
                              0,  10,  20,  30,  45,  60,  90, 
                            270, 300, 315, 330, 340, 350 };

            center = new Point ( ControlWidth / 2,
                                 ControlWidth / 2 );

            if ( tick_marks.Count > 0 )
                {
                tick_marks.Clear ( );
                }
            foreach ( int degree in tick_mark_degrees )
                {
                double      cos_radians;
                int         degrees;
                Point       from;
                int         outer_radius;
                double      radians;
                int         rotate;
                double      sin_radians ;
                Point       to;
                TickMark    tick_mark;
                TickTypes   tick_type = TickTypes.LARGE_DIAMOND;

                rotate = degree;
                degrees = rotate + 270;

                outer_radius = 0;

                radians = deg_2_rad ( ( double ) degrees );
                cos_radians =  Math.Cos ( radians );
                sin_radians =  Math.Sin ( radians );

                switch ( degree )
                    {
                    case 0:  
                        tick_type = TickTypes.LARGE_DIAMOND;
                        outer_radius = outer_ring_radius;
                        break;

                    case 10:  
                    case 20:  
                    case 340: 
                    case 350:
                        tick_type = TickTypes.SMALL_TICK;
                        outer_radius = middle_ring_radius;
                        break;

                    case 30:  
                    case 60:  
                    case 90: 
                    case 270: 
                    case 300: 
                    case 330: 
                        tick_type = TickTypes.LARGE_TICK;
                        outer_radius = outer_ring_radius;
                        break;

                    case 45:  
                    case 315: 
                        tick_type = TickTypes.SMALL_DIAMOND;
                        outer_radius = middle_ring_radius;
                        break;

                    default:
                        break;
                    }

                from = new Point ( center.X + 
                                       round ( inner_ring_radius * 
                                               cos_radians ),
                                   center.Y + 
                                       round ( inner_ring_radius * 
                                               sin_radians ) );
                to = new Point ( center.X + 
                                     round ( outer_radius * 
                                             cos_radians ),
                                 center.Y + 
                                     round ( outer_radius * 
                                             sin_radians ) );

                tick_mark = new TickMark ( degrees, 
                                           from, 
                                           to, 
                                           tick_type );
                tick_marks.Add ( tick_mark );
                }
            }

        // ******************************************* update_geometry

        void update_geometry ( )
            {

            control_center = new Point ( ControlWidth / 2,
                                         ControlWidth / 2 );

            font_size = MINIMUM_CONTROL_FONT + 
                        ( ( ControlWidth - MINIMUM_CONTROL_WIDTH ) /
                          CONTROL_WIDTH_INCREMENT );

            revise_geometry_values ( );

            generate_tick_mark_geometry ( );

            revise_background_layer = true;
            }

        // ***************************************** AttitudeIndicator

        public AttitudeIndicator ( )
            {

            Application.ApplicationExit += 
                            new EventHandler ( memory_cleanup );
            memory_cleanup ( this, EventArgs.Empty );

            control_width = ControlWidth;

            this.Width = ControlWidth;
            this.Height = ControlWidth;

            this.SetStyle ( ( ControlStyles.DoubleBuffer |
                              ControlStyles.UserPaint |
                              ControlStyles.AllPaintingInWmPaint ),
                            true );
            this.UpdateStyles ( );

            foreach ( string layer in layers )
                {
                display_layer.Add ( layer, false );
                }
            display_layer [ "Background" ] = true;
            display_layer [ "Indicator" ] = true;
            display_layer [ "Stationary" ] = true;
            }

        // ******************************************* OnCreateControl

        protected override void OnCreateControl ( )
            {

            base.OnCreateControl ( );

            current_pitch = INITIAL_PITCH;
            current_roll = INITIAL_ROLL;
            revise_background_layer = true;
            revise_attitude_layers = true;

            update_geometry ( );
            }
        // ********************************************** ControlWidth

        [ Category ( "Appearance" ),
          Description ( "Gets/Sets width of the control" ),
          DefaultValue ( 500 ),
          Bindable ( true ) ]
        public int ControlWidth
            {

            get
                {
                return ( control_width );
                }

            set
                {
                if ( value != control_width )
                    {
                    int  factor = 0;

                    control_width = value;
                    if ( control_width < MINIMUM_CONTROL_WIDTH )
                        {
                        control_width = MINIMUM_CONTROL_WIDTH;
                        }
                    factor = control_width / CONTROL_WIDTH_INCREMENT;
                    if ( ( control_width % 
                           CONTROL_WIDTH_INCREMENT ) != 0 )
                        {
                        control_width = factor * 
                                        CONTROL_WIDTH_INCREMENT;
                        }
                    update_geometry ( );
                    revise_background_layer = true;
                    this.Refresh ( );
                    }
                }
            }

        // *********************************************** CurrentRoll

        [ Category ( "Appearance" ),
          Description ( "Gets/Sets roll in degrees - plus is to right" ),
          DefaultValue ( 0 ),
          Bindable ( true ) ]
        public decimal CurrentRoll
            {

            get
                {
                return ( current_roll );
                }

            set
                {
                if ( value != current_roll )
                    {
                    current_roll = value;
                    if ( current_roll > MAXIMUM_ROLL )
                        {
                        current_roll = MAXIMUM_ROLL;
                        }
                    if ( current_roll < MINIMUM_ROLL )
                        {
                        current_roll = MINIMUM_ROLL;
                        }
                    this.Refresh ( );
                    }
                }
            }

        // ********************************************** CurrentPitch

        [ Category ( "Appearance" ),
          Description ( "Gets/Sets pitch in degrees - plus is up" ),
          DefaultValue ( 0 ),
          Bindable ( true ) ]
        public decimal CurrentPitch
            {

            get
                {
                return ( current_pitch );
                }

            set
                {
                if ( value != current_pitch )
                    {
                    current_pitch = value;
                    if ( current_pitch > MAXIMUM_PITCH )
                        {
                        current_pitch = MAXIMUM_PITCH;
                        }
                    if ( current_pitch < MINIMUM_PITCH )
                        {
                        current_pitch = MINIMUM_PITCH;
                        }
                    this.Refresh ( );
                    }
                }
            }

        // *************************************** set_clipping_region

        void set_clipping_region ( Graphics   graphics,
                                   Rectangle  bounding_rectangle )
            {
            GraphicsPath  path = null;
            Region        region = null;

            path = new GraphicsPath ( );
            path.AddEllipse ( bounding_rectangle );
            region = new Region ( path );
            graphics.SetClip ( region, CombineMode.Replace );
            }

        // *************************************** set_clipping_region

        void set_clipping_region ( Graphics graphics,
                                   Point    graphic_UL,
                                   Size     graphic_size )
            {

            set_clipping_region ( graphics, 
                                  new Rectangle ( graphic_UL,
                                                  graphic_size ) );
            }

        // *********************************** create_sky_ground_layer

        void create_sky_ground_layer ( )
            {

            if ( sky_ground_layer != null )
                {
                sky_ground_layer = sky_ground_layer.
                                   DeleteGraphicsBuffer ( );
                }
            sky_ground_layer = new GraphicsBuffer ( );
            sky_ground_layer.InitializeGraphicsBuffer ( 
                                 "SkyGround",
                                 ControlWidth,
                                 ControlWidth );
            sky_ground_layer.Graphic.SmoothingMode = 
                SmoothingMode.HighQuality;
            }

        // ************************************* draw_sky_ground_layer

        void draw_sky_ground_layer ( )
            {
            Brush               brush;
            Point               center;
            LinearGradientBrush linear_gradient_brush;
            int                 offset;
            Point               P1;
            Point               P2;
            Point               P3;
            Point               P4;
            List < Point >      point_list = new List < Point > ( );
            Pen                 pen;
            Rectangle           rectangle;
            Size                size;
            Point               UL;

            if ( sky_ground_layer == null )
                {
                create_sky_ground_layer ( );
                }

            center = new Point ( sky_ground_layer.Width / 2,
                                 sky_ground_layer.Height / 2 );
            offset = ( control_width - outer_ring_diameter ) / 2;
            UL = new Point ( offset, offset );
            size = new Size ( outer_ring_diameter, 
                              outer_ring_diameter );
            set_clipping_region ( sky_ground_layer.Graphic,
                                  UL,
                                  size );
                                        // sky hemisphere fill
            rectangle = new Rectangle ( UL, size );
            linear_gradient_brush = new LinearGradientBrush (
                                    new Point ( 0, 0 ),
                                    new Point ( 0,
                                                center.Y + 
                                                outer_ring_radius ),
                                    Color.DodgerBlue,
                                    Color.SkyBlue );
            sky_ground_layer.Graphic.FillRectangle ( 
                                            linear_gradient_brush, 
                                            rectangle );
            linear_gradient_brush.Dispose ( );
                                        // ground hemisphere fill
            brush = new SolidBrush ( LOWER_HEMISPHERE_COLOR );
            P1 = new Point ( center.X - outer_ring_radius, 
                             center.Y );
            P2 = new Point ( center.X - outer_ring_radius / 2 + 2, 
                             P1.Y );
            P3 = new Point ( P2.X, center.Y + outer_ring_radius );
            P4 = new Point ( P1.X, P3.Y );

            point_list.Add ( P1 );
            point_list.Add ( P2 );
            point_list.Add ( P3 );
            point_list.Add ( P4 );
            sky_ground_layer.Graphic.FillPolygon ( 
                                            brush, 
                                            point_list.ToArray ( ) );

            point_list.Clear ( );

            P1 = new Point ( center.X + outer_ring_radius / 2, 
                             center.Y );
            P2 = new Point ( center.X + outer_ring_radius, P1.Y );
            P3 = new Point ( P2.X, center.Y + outer_ring_radius );
            P4 = new Point ( P1.X, P3.Y );

            point_list.Add ( P1 );
            point_list.Add ( P2 );
            point_list.Add ( P3 );
            point_list.Add ( P4 );

            sky_ground_layer.Graphic.FillPolygon ( 
                                            brush, 
                                            point_list.ToArray ( ) );
            point_list.Clear ( );
            brush.Dispose ( );
                                        // hemisphere separator
            P1 = new Point ( offset, center.Y );
            P2 = new Point ( center.X + outer_ring_diameter, 
                             center.Y );
            pen = new Pen ( Color.White, TICK_MARK_THICKNESS );
            sky_ground_layer.Graphic.DrawLine ( pen, P1, P2 );
            pen.Dispose ( );
            }

        // *********************************** create_top_bottom_layer

        void create_top_bottom_layer ( )
            {

            if ( top_bottom_layer != null )
                {
                top_bottom_layer = top_bottom_layer.
                                   DeleteGraphicsBuffer ( );
                }
            top_bottom_layer = new GraphicsBuffer ( );
            top_bottom_layer.InitializeGraphicsBuffer ( 
                                 "TopBottom",
                                 ControlWidth,
                                 ControlWidth );
            top_bottom_layer.Graphic.SmoothingMode = 
                SmoothingMode.HighQuality;
            }

        // ************************************* draw_top_bottom_layer

        // Note: various constants used in this method were derived by 
        // experimenting. 

        void draw_top_bottom_layer ( )
            {
            Brush               brush;
            Point               center;
            GraphicsPath        inner_path;
            Rectangle           inner_rectangle;
            Region              inner_region;
            int                 offset;
            GraphicsPath        outer_path;
            Rectangle           outer_rectangle;
            Region              outer_region;
            Size                size;
            Point               UL;

            if ( top_bottom_layer == null )
                {
                create_top_bottom_layer ( );
                }

            center = new Point ( top_bottom_layer.Width / 2,
                                 top_bottom_layer.Height / 2 );
            offset = ( control_width - outer_ring_diameter ) / 2;
            UL = new Point ( offset, offset );
            size = new Size ( outer_ring_diameter, 
                              outer_ring_diameter );
            set_clipping_region ( top_bottom_layer.Graphic,
                                  UL,
                                  size );
                                        // sky annulus
            UL =  new Point ( center.X - 29 * orr_div_10, 
                              center.Y - outer_ring_radius );
            size = new Size ( 58 * orr_div_10, 58 * orr_div_10 );
            outer_rectangle = new Rectangle ( UL, size );
                                        // compute outer geometry
            outer_path = new GraphicsPath ( );
            outer_path.AddEllipse ( outer_rectangle );
            outer_region = new Region ( outer_path );
                                        // compute inner geometry
            UL = new Point ( center.X - 25 * orr_div_10, 
                             center.Y - 
                             round ( 7.5F * ( float ) orr_div_10 ) );
            size = new Size ( 50 * orr_div_10, 50 * orr_div_10 );
            inner_rectangle = new Rectangle ( UL, size );
            inner_path = new GraphicsPath ( );
            inner_path.AddEllipse ( inner_rectangle );
            inner_region = new Region ( inner_path );
                                        // exclude inner from outer
            outer_region.Exclude ( inner_region );
                                        // fill the region
            brush = new SolidBrush ( UPPER_HEMISPHERE_TOP );
            top_bottom_layer.Graphic.FillRegion ( 
                            brush, 
                            outer_region );
            brush.Dispose ( );
                                        // ground annulus
            UL =  new Point ( center.X - 29 * orr_div_10, 
                              center.Y - 46 * orr_div_10 );
            size = new Size ( 58 * orr_div_10, 58 * orr_div_10 );
            outer_rectangle = new Rectangle ( UL, size );
                                        // compute outer geometry
            outer_path = new GraphicsPath ( );
            outer_path.AddEllipse ( outer_rectangle );
            outer_region = new Region ( outer_path );
                                        // compute inner geometry
            UL = new Point ( center.X - 25 * orr_div_10, 
                             center.Y - 
                             round ( 42.5F * ( float ) orr_div_10 ) );
            size = new Size ( 50 * orr_div_10, 50 * orr_div_10 );
            inner_rectangle = new Rectangle ( UL, size );
            inner_path = new GraphicsPath ( );
            inner_path.AddEllipse ( inner_rectangle );
            inner_region = new Region ( inner_path );
                                        // exclude inner from outer
            outer_region.Exclude ( inner_region );
            top_bottom_layer.Graphic.FillRegion ( 
                            new SolidBrush ( Color.SaddleBrown ), 
                            outer_region );
            }

        // *********************************** create_stationary_layer

        void create_stationary_layer ( )
            {

            if ( stationary_layer != null )
                {
                stationary_layer = stationary_layer.
                                   DeleteGraphicsBuffer ( );
                }
            stationary_layer = new GraphicsBuffer ( );
            stationary_layer.InitializeGraphicsBuffer ( 
                                 "Stationary",
                                 ControlWidth,
                                 ControlWidth );
            stationary_layer.Graphic.SmoothingMode = 
                SmoothingMode.HighQuality;
            }

        // ************************************* draw_stationary_layer

        void draw_stationary_layer ( )
            {
            Brush           brush;
            int             diameter;
            Size            graphic_size;
            Point           graphic_UL;
            Point           P;
            Point           P1;
            Point           P2;
            Point           P3;
            Point           P4;
            Point           P5;
            Point           P6;
            Point           P7;
            Point           P8;
            Point           P9;
            Point           P10;
            Point           P11;
            Point           P12;
            Point           P13;
            List < Point >  point_list = new List < Point > ( );
            Pen             pen;
            int             radius;
            Rectangle       rectangle;

            if ( stationary_layer == null )
                {
                create_stationary_layer ( );
                }

            brush = new SolidBrush ( Color.Black );
            radius = round ( ( float ) ControlWidth / 160.0F );
            diameter = 2 * radius;
            graphic_UL = new Point ( control_center.X - radius,
                                     control_center.Y - radius );
            graphic_size = new Size ( diameter, diameter );
            rectangle = new Rectangle ( graphic_UL, graphic_size );
            stationary_layer.Graphic.FillEllipse ( brush, rectangle );
            brush.Dispose ( );            

            P1 = new Point ( control_center.X - 10 * diameter,
                             control_center.Y );
            P2 = new Point ( control_center.X - 3 * diameter, 
                             P1.Y );
            P3 = new Point ( P2.X,
                             control_center.Y + 2 * diameter );
            P4 = new Point ( P2.X,
                             control_center.Y + 4 * diameter );
            P5 = new Point ( control_center.X + 3 * diameter, 
                             P4.Y );
            P6 = new Point ( P5.X, P3.Y );
            P7 = new Point ( P5.X, P1.Y );
            P8 = new Point ( control_center.X + 10 * diameter, 
                             P1.Y );
            P = new Point ( control_center.X, P3.Y );

            P10 = new Point ( control_center.X - 
                              round ( 1.5F * ( float ) diameter ), 
                              control_center.Y + inner_ring_radius -
                              6 * diameter );
            P11 = new Point ( control_center.X - 3 * diameter,
                              control_center.Y + inner_ring_radius );
            P12 = new Point ( control_center.X + 3 * diameter, 
                              P11.Y );
            P13 = new Point ( control_center.X + 
                              round ( 1.5F * ( float ) diameter ),
                              P10.Y );

            P9 = new Point ( P.X, P10.Y );

            if ( point_list.Count > 0 )
                {
                point_list.Clear ( );
                }
                                        // order is important: 
                                        //   top left, 
                                        //   top right, 
                                        //   top left
                                        //   down, across, and up
                                        //   center vertical
                                        //   black line under wings
                                        //   base
                                        //   upward tick mark
            point_list.Add ( P1 );
            point_list.Add ( P2 );
            point_list.Add ( P3 );
            pen = new Pen ( Color.LightGoldenrodYellow, 
                            ( float ) diameter );
            pen.StartCap = LineCap.Square;
            pen.EndCap = LineCap.Square;
            stationary_layer.Graphic.DrawLines ( 
                                            pen,
                                            point_list.ToArray ( ) );
            point_list.Clear ( );
            pen.Dispose ( );
                                        // top right
            point_list.Add ( P6 );
            point_list.Add ( P7 );
            point_list.Add ( P8 );
            pen = new Pen ( Color.LightGoldenrodYellow, 
                            ( float ) diameter );
            pen.StartCap = LineCap.Square;
            pen.EndCap = LineCap.Square;
            stationary_layer.Graphic.DrawLines ( 
                                            pen,
                                            point_list.ToArray ( ) );
            point_list.Clear ( );
            pen.Dispose ( );
                                        // down, across, and up
            point_list.Add ( P3 );
            point_list.Add ( P4 );
            point_list.Add ( P5 );
            point_list.Add ( P6 );
            pen = new Pen ( Color.Brown, ( float ) diameter );
            pen.StartCap = LineCap.Square;
            pen.EndCap = LineCap.Square;
            stationary_layer.Graphic.DrawLines ( 
                                            pen,
                                            point_list.ToArray ( ) );
            point_list.Clear ( );
            pen.Dispose ( );
                                        // center vertical
            pen = new Pen ( Color.Brown, ( float ) diameter );
            pen.StartCap = LineCap.Square;
            pen.EndCap = LineCap.Square;
            stationary_layer.Graphic.DrawLine ( pen, P, P9 );
            pen.Dispose ( );
                                        // black line under wings
            point_list.Add ( new Point ( P1.X - radius, 
                                         P1.Y + radius ) );
            point_list.Add ( new Point ( P2.X - radius, 
                                         P2.Y + radius ) );
            point_list.Add ( new Point ( P4.X - radius, 
                                         P4.Y + radius ) );
            point_list.Add ( new Point ( P5.X + radius, 
                                         P5.Y + radius ) );
            point_list.Add ( new Point ( P7.X + radius, 
                                         P7.Y + radius ) );
            point_list.Add ( new Point ( P8.X + radius, 
                                         P8.Y + radius ) );

            pen = new Pen ( Color.Black, 2.0F );
            stationary_layer.Graphic.DrawLines ( 
                                            pen,
                                            point_list.ToArray ( ) );
            point_list.Clear ( );
            pen.Dispose ( );
                                        // base
            point_list.Add ( P10 );
            point_list.Add ( P11 );
            point_list.Add ( P12 );
            point_list.Add ( P13 );
            point_list.Add ( P10 );
            brush = new SolidBrush ( Color.Brown );
            stationary_layer.Graphic.FillPolygon ( 
                                            brush,
                                            point_list.ToArray ( ) );
            point_list.Clear ( );
            pen.Dispose ( );
                                        // upward tick mark
            brush = new SolidBrush ( Color.Yellow );
            pen = new Pen ( Color.Black );
            P1 = new Point ( control_center.X,
                             control_center.Y - inner_ring_radius );
            P2 = new Point ( control_center.X - tick_mark_half_base, 
                             P1.Y + tick_mark_height );
            P3 = new Point ( P2.X + tick_mark_base,
                             P2.Y );

            point_list.Add ( P1 );
            point_list.Add ( P2 );
            point_list.Add ( P3 );
            point_list.Add ( P1 );

            stationary_layer.Graphic.FillPolygon ( 
                                            brush,
                                            point_list.ToArray ( ) );
            stationary_layer.Graphic.DrawPolygon ( 
                                            pen,
                                            point_list.ToArray ( ) );
            point_list.Clear ( );
            pen.Dispose ( );
            brush.Dispose ( );
            }

        // *********************************** create_background_layer

        void create_background_layer ( )
            {

            if ( background_layer != null )
                {
                background_layer = background_layer.
                                   DeleteGraphicsBuffer ( );
                }
            background_layer = new GraphicsBuffer ( );
            background_layer.InitializeGraphicsBuffer ( 
                                           "Background",
                                           ControlWidth,
                                           ControlWidth );
            background_layer.Graphic.SmoothingMode = 
                                            SmoothingMode.HighQuality;
            }

        // ************************************ rounded_rectangle_path

        /// <summary>
        /// computes the GraphicsPath of a rounded rectangle
        /// </summary>
        /// <param name="x">
        /// x coordinate of the upper left corner of the rectangle
        /// </param>
        /// <param name="y">
        /// y coordinate of the upper left corner of the rectangle
        /// </param>
        /// <param name="width">
        /// width of the rectangle
        /// </param>
        /// <param name="height">
        /// height of the rectangle
        /// </param>
        /// <param name="radius">
        /// radius of the circle that defines the rounded corner
        /// </param>
        /// <returns>
        /// the GraphicsPath that defines the rounded rectangle
        /// </returns>
        GraphicsPath rounded_rectangle_path ( int x,
                                              int y,
                                              int width,
                                              int height,
                                              int radius )
            {
            int           diameter = 2 * radius;
            GraphicsPath  path = new GraphicsPath ( );

            path.StartFigure ( );
            path.AddArc ( ( x + width - diameter ), 
                          ( y + height - diameter ), 
                          diameter, 
                          diameter, 
                          0.0F, 
                          90.0F );
            path.AddArc ( x, 
                          ( y + height - diameter ), 
                          diameter, 
                          diameter, 
                          90.0F, 
                          90.0F );
            path.AddArc ( x, 
                          y, 
                          diameter, 
                          diameter, 
                          180.0F, 
                          90.0F );
            path.AddArc ( ( x + width - diameter ), 
                          y, 
                          diameter, 
                          diameter, 
                          270.0F, 
                          90.0F );
            path.CloseFigure ( );

            return ( path );
            }

        // ************************************ rounded_rectangle_path

        /// <summary>
        /// computes the GraphicsPath of a rounded rectangle
        /// </summary>
        /// <param name="rectangle">
        /// the rectangle for which rounding is desired
        /// </param>
        /// <param name="radius">
        /// radius of the circle that defines the rounded corner
        /// </param>
        /// <returns>
        /// the GraphicsPath that defines the rounded rectangle
        /// </returns>
        GraphicsPath rounded_rectangle_path ( Rectangle  rectangle,
                                              int        radius )
            {

            return ( rounded_rectangle_path ( rectangle.X,
                                              rectangle.Y,
                                              rectangle.Width,
                                              rectangle.Height,
                                              radius ) );
            }

        // ************************************* draw_background_layer

        void draw_background_layer ( )
            {
            Brush           brush;
            int             diameter;
            Size            graphic_size;
            Point           graphic_UL;
            Rectangle       instrument_rectangle;
            int             instrument_ring_diameter = 0;
            int             instrument_ring_offset = 0;
            GraphicsPath    path;
            Pen             pen;
            Rectangle       rectangle;
            Region          region = null;
            Rectangle       rounded_rectangle;

            if ( background_layer == null )
                {
                create_background_layer ( );
                }

                                        // rounded rectangle
            brush = new SolidBrush ( CONTROL_BACKGROUND );
            rounded_rectangle = new Rectangle ( 0, 
                                                0, 
                                                ControlWidth, 
                                                ControlWidth );
            path = rounded_rectangle_path ( rounded_rectangle, 
                                            ControlWidth / 10 );
                                        // clip to rounded rectangle
            region = new Region ( path );
            background_layer.Graphic.SetClip ( region, 
                                               CombineMode.Replace );
                                        // fill rounded rectangle
            background_layer.Graphic.FillPath ( brush, path );
            region.Dispose ( );
            path.Dispose ( );
            brush.Dispose ( );
                                        // instrument circle
            brush = new SolidBrush ( INDICATOR_BACKGROUND );
            pen = new Pen ( INDICATOR_FONT_COLOR, 3.0F );
            instrument_ring_offset = 
                round ( ( float ) ControlWidth / 40.0F );
            instrument_ring_diameter = ControlWidth - 
                                       ( 2 * instrument_ring_offset );
            graphic_UL = new Point ( instrument_ring_offset, 
                                     instrument_ring_offset );
            graphic_size = new Size ( instrument_ring_diameter, 
                                      instrument_ring_diameter );
            instrument_rectangle = new Rectangle ( graphic_UL, 
                                                   graphic_size );
            background_layer.Graphic.DrawEllipse ( 
                                            pen, 
                                            instrument_rectangle );
            background_layer.Graphic.FillEllipse ( 
                                            brush, 
                                            instrument_rectangle );
            set_clipping_region ( background_layer.Graphic,
                                  graphic_UL,
                                  graphic_size );
            brush.Dispose ( );
            pen.Dispose ( );
                                        // inner circle
            brush = new SolidBrush ( CONTROL_BACKGROUND );
            pen = new Pen ( INDICATOR_FONT_COLOR, 1.0F );
            diameter = ControlWidth - ( 2 * instrument_offset );
            graphic_UL = new Point ( instrument_offset, 
                                     instrument_offset );
            graphic_size = new Size ( diameter, diameter );
            rectangle = new Rectangle ( graphic_UL, graphic_size );
            background_layer.Graphic.DrawEllipse ( pen, rectangle );
            background_layer.Graphic.FillEllipse ( brush, rectangle );
            brush.Dispose ( );
            pen.Dispose ( );
            }

        // **************************************** create_pitch_layer

        void create_pitch_layer ( )
            {

            if ( pitch_layer != null )
                {
                pitch_layer = pitch_layer.DeleteGraphicsBuffer ( );
                }
            pitch_layer = new GraphicsBuffer ( );
            pitch_layer.InitializeGraphicsBuffer ( 
                                            "Pitch",
                                            ControlWidth,
                                            ControlWidth );
            pitch_layer.Graphic.SmoothingMode = SmoothingMode.
                                                    HighQuality;
            }

        // ****************************************** draw_pitch_scale

        void draw_pitch_scale ( Graphics    graphic,
                                Point       center,
                                int         x_offset,
                                int         y_offset,
                                string      label,
                                Font        font )
            {
            Brush   brush = new SolidBrush ( TICK_MARK_COLOR );
            Point   P1;
            Point   P2;
            Pen     pen = new Pen ( TICK_MARK_COLOR, 
                                    TICK_MARK_THICKNESS );
            Size    size;

            size = TextRenderer.MeasureText ( label, font );
            P1 = new Point ( center.X - x_offset,
                             center.Y - y_offset );
            P2 = new Point ( center.X + x_offset, P1.Y );
            graphic.DrawLine ( pen, P1, P2 );
            if ( !String.IsNullOrEmpty ( label ) )
                {
                graphic.DrawString ( 
                            label,
                            font,
                            brush,
                            new Point ( P1.X - size.Width, 
                                        P1.Y - size.Height / 2 ) );
                graphic.DrawString ( 
                            label,
                            font,
                            brush,
                            new Point ( P2.X, 
                                        P2.Y - size.Height / 2 ) );
                }
            brush.Dispose ( );
            pen.Dispose ( );
            }

        // ****************************************** draw_pitch_scale

        void draw_pitch_scale ( Graphics    graphic,
                                Point       center,
                                int         x_offset,
                                int         y_offset )
            {
            Point   P1;
            Point   P2;
            Pen     pen = new Pen ( TICK_MARK_COLOR, 
                                    TICK_MARK_THICKNESS );

            P1 = new Point ( center.X - x_offset,
                             center.Y - y_offset );
            P2 = new Point ( center.X + x_offset, P1.Y );
            graphic.DrawLine ( pen, P1, P2 );
            pen.Dispose ( );
            }

        // ****************************************** draw_pitch_layer

        void draw_pitch_layer ( )
            {
            Brush           brush;
            Point           center;
            Font            font;
            float           orr_div_10;
            Point           P1;
            Point           P2;
            Point           P3;
            Point           P4;
            List < Point >  point_list = new List < Point > ( );

            if ( pitch_layer == null)
                {
                create_pitch_layer ( );
                }

            center = new Point ( pitch_layer.Width / 2,
                                 pitch_layer.Height / 2 );
            font = new Font ( FONT_FAMILY, 
                              round ( 1.0F * ( float ) font_size ),
                              FontStyle.Bold,
                              GraphicsUnit.Pixel );
            orr_div_10 = ( float ) outer_ring_radius / 10.0F;
                                        // pitch background
            brush = new SolidBrush ( LOWER_HEMISPHERE_COLOR );

            P1 = new Point ( center.X - outer_ring_radius / 2, 
                             center.Y );
            P2 = new Point ( center.X + outer_ring_radius / 2, P1.Y );
            P3 = new Point ( P2.X, center.Y + outer_ring_diameter );
            P4 = new Point ( P1.X, P3.Y );

            point_list.Add ( P1 );
            point_list.Add ( P2 );
            point_list.Add ( P3 );
            point_list.Add ( P4 );
            pitch_layer.Graphic.FillPolygon ( 
                                            brush, 
                                            point_list.ToArray ( ) );
            point_list.Clear ( );
            brush.Dispose ( );
                                        // pitch scale
            draw_pitch_scale ( pitch_layer.Graphic,
                               center,
                               round ( 1.5F * orr_div_10 ),
                               round ( 4.0F * orr_div_10 ),
                               "40",
                               font );
            draw_pitch_scale ( pitch_layer.Graphic,
                               center,
                               round ( 1.0F * orr_div_10 ),
                               round ( 3.5F * orr_div_10 ) );
            draw_pitch_scale ( pitch_layer.Graphic,
                               center,
                               round ( 1.5F * orr_div_10 ),
                               round ( 3.0F * orr_div_10 ),
                               "30",
                               font );
            draw_pitch_scale ( pitch_layer.Graphic,
                               center,
                               round ( 1.0F * orr_div_10 ),
                               round ( 2.5F * orr_div_10 ) );
            draw_pitch_scale ( pitch_layer.Graphic,
                               center,
                               round ( 1.5F * orr_div_10 ),
                               round ( 2.0F * orr_div_10 ),
                               "20",
                               font );
            draw_pitch_scale ( pitch_layer.Graphic,
                               center,
                               round ( 1.0F * orr_div_10 ),
                               round ( 1.5F * orr_div_10 ) );
            draw_pitch_scale ( pitch_layer.Graphic,
                               center,
                               round ( 1.5F * orr_div_10 ),
                               round ( 1.0F * orr_div_10 ),
                               "10",
                               font );
            draw_pitch_scale ( pitch_layer.Graphic,
                               center,
                               round ( 1.0F * orr_div_10 ),
                               round ( 0.5F * orr_div_10 ) );
            draw_pitch_scale ( pitch_layer.Graphic,
                               center,
                               round ( 1.5F * orr_div_10 ),
                               0 );
            draw_pitch_scale ( pitch_layer.Graphic,
                               center,
                               round ( 1.0F * orr_div_10 ),
                               -round ( 0.5F * orr_div_10 ) );
            draw_pitch_scale ( pitch_layer.Graphic,
                               center,
                               round ( 1.5F * orr_div_10 ),
                               -round ( 1.0F * orr_div_10 ),
                               "10",
                               font );
            draw_pitch_scale ( pitch_layer.Graphic,
                               center,
                               round ( 1.0F * orr_div_10 ),
                               -round ( 1.5F * orr_div_10 ) );
            draw_pitch_scale ( pitch_layer.Graphic,
                               center,
                               round ( 1.5F * orr_div_10 ),
                               -round ( 2.0F * orr_div_10 ),
                               "20",
                               font );
            draw_pitch_scale ( pitch_layer.Graphic,
                               center,
                               round ( 1.0F * orr_div_10 ),
                               -round ( 2.5F * orr_div_10 ) );
            draw_pitch_scale ( pitch_layer.Graphic,
                               center,
                               round ( 1.5F * orr_div_10 ),
                               -round ( 3.0F * orr_div_10 ),
                               "30",
                               font );
            draw_pitch_scale ( pitch_layer.Graphic,
                               center,
                               round ( 1.0F * orr_div_10 ),
                               -round ( 3.5F * orr_div_10 ) );
            draw_pitch_scale ( pitch_layer.Graphic,
                               center,
                               round ( 1.5F * orr_div_10 ),
                               -round ( 4.0F * orr_div_10 ),
                               "40",
                               font );
            }

        // ***************************************** create_roll_layer

        void create_roll_layer ( )
            {

            if ( roll_layer != null )
                {
                roll_layer = roll_layer.DeleteGraphicsBuffer ( );
                }
            roll_layer = new GraphicsBuffer ( );
            roll_layer.InitializeGraphicsBuffer ( 
                                            "Roll",
                                            ControlWidth,
                                            ControlWidth );
            roll_layer.Graphic.SmoothingMode = SmoothingMode.
                                                   HighQuality;
            }

        // ******************************************* draw_roll_layer

        void draw_roll_layer ( )
            {
            Brush               brush;
            Point               center;
            ColorBlend          color_blend;
            Color [ ]           colors = { UPPER_HEMISPHERE_TOP,
                                           UPPER_HEMISPHERE_BOTTOM,
                                           LOWER_HEMISPHERE_TOP,
                                           LOWER_HEMISPHERE_BOTTOM };
            GraphicsPath        inner_path;
            Rectangle           inner_rectangle;
            Region              inner_region;
            LinearGradientBrush linear_gradient_brush;
            int                 offset;
            int                 orr_less_irr;
            GraphicsPath        outer_path;
            Rectangle           outer_rectangle;
            Region              outer_region;
            Point               P1;
            Point               P2;
            Point               P3;
            Pen                 pen;
            List < Point >      point_list = new List < Point > ( );
            float [ ]           positions = { 0.0F, 
                                              0.5F, 
                                              0.5F, 
                                              1.0F };
            Size                size;
            Point               UL;

            if ( roll_layer == null )
                {
                create_roll_layer ( );
                }

            center = new Point ( roll_layer.Width / 2,
                                 roll_layer.Height / 2 );
            orr_less_irr = outer_ring_radius - inner_ring_radius;
            offset = ( control_width - outer_ring_diameter ) / 2;
                                        // annulus
            UL = new Point ( offset, offset );
            size = new Size ( outer_ring_diameter, 
                              outer_ring_diameter );
                                        // compute outer geometry
            outer_rectangle = new Rectangle ( UL, size );
            outer_path = new GraphicsPath ( );
            outer_path.AddEllipse ( outer_rectangle );
            outer_region = new Region ( outer_path );
                                        // compute inner geometry
            UL = new Point ( offset + orr_less_irr,
                             offset + orr_less_irr );
            size = new Size ( inner_ring_diameter,
                              inner_ring_diameter );
            inner_rectangle = new Rectangle ( UL, size );
            inner_path = new GraphicsPath ( );
            inner_path.AddEllipse ( inner_rectangle );
            inner_region = new Region ( inner_path );
                                        // exclude inner from outer
            outer_region.Exclude ( inner_region );
                                        // paint the annulus
            color_blend = new ColorBlend ( );
            color_blend.Colors = colors;
            color_blend.Positions = positions;
            linear_gradient_brush = new LinearGradientBrush (
                                new Point ( offset, offset ),
                                new Point ( offset, 
                                            offset + 
                                                outer_ring_diameter ),
                                UPPER_HEMISPHERE_TOP,
                                UPPER_HEMISPHERE_BOTTOM );
            linear_gradient_brush.InterpolationColors = color_blend;
            roll_layer.Graphic.FillRegion ( linear_gradient_brush, 
                                            outer_region );
            linear_gradient_brush.Dispose ( );
            outer_region.Dispose ( );
            outer_path.Dispose ( );
            inner_region.Dispose ( );
            inner_path.Dispose ( );
                                        // large diamond
            brush = new SolidBrush ( TICK_MARK_COLOR );
            point_list.Clear ( );
            P1 = new Point ( center.X,
                             center.Y - inner_ring_radius );
            P2 = new Point ( center.X - tick_mark_base,
                             center.Y - outer_ring_radius );
            P3 = new Point ( center.X + tick_mark_base,
                             center.Y - outer_ring_radius );
            point_list.Add ( P1 );
            point_list.Add ( P2 );
            point_list.Add ( P3 );
            point_list.Add ( P1 );
            roll_layer.Graphic.FillPolygon ( brush,
                                             point_list.ToArray ( ) );
            point_list.Clear ( );
            brush.Dispose ( );
                                        // tick marks & small diamonds
            brush = new SolidBrush ( TICK_MARK_COLOR );
            pen = new Pen ( TICK_MARK_COLOR );
            foreach ( TickMark tick_mark in tick_marks )
                {
                int         degrees = tick_mark.Degrees + 90;
                Point       from = tick_mark.From;
                bool        is_diamond = false;
                double      radians;
                int         tick_base = 0;
                int         tick_half_base = 0;
                int         tick_height = 0;
                TickTypes   tick_type = tick_mark.TickType;
                Point       to = tick_mark.To;

                switch ( tick_type )
                    {
                    case TickTypes.LARGE_DIAMOND:
                        continue;

                    case TickTypes.LARGE_TICK:
                        pen.Width = 5.0F;
                        break;

                    case TickTypes.SMALL_DIAMOND:
                        tick_base = tick_mark_base;
                        tick_half_base = tick_mark_half_base;
                        tick_height = tick_mark_height;
                        is_diamond = true;
                        break;

                    case TickTypes.SMALL_TICK:
                        pen.Width = 3.0F;
                        break;
                    }

                if ( is_diamond )
                    {
                    radians = deg_2_rad ( degrees );

                    P1 = new Point ( -tick_half_base, 0 );
                    P2 = new Point ( tick_half_base, 0 );
                                        // 5 is MAGIC; fits irr
                    P3 =new Point ( 0, ( tick_height - 6 ) );

                    point_list.Clear ( );
                    point_list.Add ( P1 );
                    point_list.Add ( P2 );
                    point_list.Add ( P3 );
                    point_list.Add ( P1 );

                    roll_layer.Graphic.TranslateTransform ( to.X,
                                                            to.Y );
                    roll_layer.Graphic.RotateTransform (
                                            ( float ) degrees ); 
                    roll_layer.Graphic.FillPolygon ( 
                                            brush,
                                            point_list.ToArray ( ) ) ;
                    roll_layer.Graphic.ResetTransform ( );
                    point_list.Clear ( );
                    }
                else
                    {
                    roll_layer.Graphic.DrawLine ( pen, from, to );
                    }
                }            
            point_list.Clear ( );
            brush.Dispose ( );
            pen.Dispose ( );
                                        // hemisphere divider
            pen = new Pen ( TICK_MARK_COLOR );
            P1 = new Point ( center.X - inner_ring_radius, 
                             center.Y );
            P2 = new Point ( center.X + inner_ring_radius, 
                             center.Y );
            roll_layer.Graphic.DrawLine ( pen, P1, P2 );
            pen.Dispose ( );
            }

        // ************************************ create_indicator_layer

        void create_indicator_layer ( )
            {

            if ( indicator_layer != null )
                {
                indicator_layer = indicator_layer.
                                  DeleteGraphicsBuffer ( );
                }
            indicator_layer = new GraphicsBuffer ( );
            indicator_layer.InitializeGraphicsBuffer ( "Indicator",
                                                       ControlWidth,
                                                       ControlWidth );
            indicator_layer.Graphic.SmoothingMode = SmoothingMode.
                                                    HighQuality;
            }

        // ********************************************* rotate_bitmap

        // http://stackoverflow.com/questions/5172906/
        //     c-rotating-graphics

        /// <summary>
        /// rotate a bitmap by a specified angle, in degrees
        /// </summary>
        /// <param name="bitmap">
        /// bitmap to rotate
        /// </param>
        /// <param name="angle">
        /// angle, in degrees, by which to rotate bitmap
        /// </param>
        /// <returns>
        /// the rotated bitmap
        /// </returns>
        Bitmap rotate_bitmap ( Bitmap  bitmap, 
                               float   angle )
            {
            Bitmap return_bitmap;
                                        // create empty bitmap to hold 
                                        // rotated image
            return_bitmap = new Bitmap ( bitmap.Width, 
                                         bitmap.Height );
                                        // make a graphic object from 
                                        // the empty bitmap
            using ( Graphics graphic = Graphics.FromImage ( 
                                                    return_bitmap ) )
                {
                                        // translate rotation point to 
                                        // center of image
                graphic.TranslateTransform ( 
                                    ( float ) bitmap.Width / 2.0F, 
                                    ( float ) bitmap.Height / 2.0F );
                                        // rotate image
                graphic.RotateTransform ( angle );
                                        //move image back
                graphic.TranslateTransform ( 
                                    -( float ) bitmap.Width / 2.0F, 
                                    -( float ) bitmap.Height / 2.0F );
                                        // draw passed in image onto 
                                        // graphic object
                graphic.DrawImage ( bitmap, new Point ( 0, 0 ) );

                graphic.ResetTransform ( );
                }

            return ( return_bitmap );
            }

        // ************************************** draw_indicator_layer

        void draw_indicator_layer ( )
            {
            Bitmap          bitmap;
            decimal         cos_roll_rad;
            float           dx;
            float           dy;
            int             offset;
            decimal         orr_div_10;
            int             pitch;
            double          roll_rad;
            decimal         sin_roll_rad;
            Size            size;
            Point           UL;
            int             x;
            float           x_offset;
            int             y;
            float           y_offset;

            if ( indicator_layer == null )
                {
                create_indicator_layer ( );
                }

            if ( pitch_layer == null )
                {
                create_pitch_layer ( );
                draw_pitch_layer ( );
                }

            if ( roll_layer == null )
                {
                create_roll_layer ( );
                draw_roll_layer ( );
                }

            if ( sky_ground_layer == null )
                {
                create_sky_ground_layer ( );
                draw_sky_ground_layer ( );
                }

            if ( top_bottom_layer == null )
                {
                create_top_bottom_layer ( );
                draw_top_bottom_layer ( );
                }
                                        // set the clipping region
            offset = ( control_width - outer_ring_diameter ) / 2;
            UL = new Point ( offset, offset );
            size = new Size ( outer_ring_diameter, 
                              outer_ring_diameter );
            set_clipping_region ( indicator_layer.Graphic, UL, size );
                                        // insert sky/ground
            bitmap = rotate_bitmap ( sky_ground_layer.Bitmap,
                                    ( float ) CurrentRoll );
            indicator_layer.Graphic.DrawImage ( bitmap, 
                                                new Point ( 0, 0 ) );
                                        // insert pitch
            orr_div_10 = ( decimal ) outer_ring_radius / 10.0M;
            pitch = round ( ( CurrentPitch / MAXIMUM_PITCH ) * 
                            ( 4.0M * orr_div_10 ) );
            roll_rad = deg_2_rad ( ( double ) CurrentRoll );
            sin_roll_rad = ( decimal ) Math.Sin ( roll_rad );
            cos_roll_rad = ( decimal ) Math.Cos ( roll_rad );
            dx = ( float ) ( pitch * sin_roll_rad );
            x_offset = ( float ) control_center.X - 
                       ( ( float ) pitch_layer.Width / 2.0F );
            x = round ( x_offset - dx );
            dy = ( float ) ( pitch * cos_roll_rad );
            y_offset = ( float ) control_center.Y - 
                       ( ( float ) pitch_layer.Height / 2.0F );
            y = round ( y_offset + dy );
            bitmap = rotate_bitmap ( pitch_layer.Bitmap,
                                    ( float ) CurrentRoll );
            indicator_layer.Graphic.TranslateTransform ( x, y );
            indicator_layer.Graphic.DrawImage ( bitmap, 
                                                new Point ( 0, 0 ) );
            indicator_layer.Graphic.ResetTransform ( );
                                        // insert top/bottom image
            bitmap = rotate_bitmap ( top_bottom_layer.Bitmap,
                                    ( float ) CurrentRoll );
            indicator_layer.Graphic.DrawImage ( bitmap, 
                                                new Point ( 0, 0 ) );
                                        // insert roll image
            bitmap = rotate_bitmap ( roll_layer.Bitmap,
                                    ( float ) CurrentRoll );
            indicator_layer.Graphic.DrawImage ( bitmap, 
                                                new Point ( 0, 0 ) );
            }

        // ********************************* adjust_control_dimensions

        void adjust_control_dimensions ( int new_height,
                                         int new_width )
            {
            int  factor = 0;

            control_width = new_height;
            if ( new_width < control_width )
                {
                control_width = new_width;
                }

            if ( control_width < MINIMUM_CONTROL_WIDTH )
                {
                control_width = MINIMUM_CONTROL_WIDTH;
                }
            factor = control_width / CONTROL_WIDTH_INCREMENT;
            if ( ( control_width %
                   CONTROL_WIDTH_INCREMENT ) != 0 )
                {
                control_width = factor *
                                CONTROL_WIDTH_INCREMENT;
                }

            this.Width = control_width;
            this.Height = control_width;

            update_geometry ( );

            revise_background_layer = true;
            revise_attitude_layers = true;
            }

        // ************************************************** OnResize

        protected override void OnResize ( EventArgs e )
            {

            base.OnResize ( e );

            adjust_control_dimensions ( this.Height, this.Width );

            this.Refresh ( );
            }

        // ************************ make_control_backround_transparent

        void make_control_backround_transparent ( PaintEventArgs e )
            { 
            Rectangle           clipping_rectangle;
            PaintEventArgs      paint_event_args;
            GraphicsContainer   state;

            state = e.Graphics.BeginContainer();
            e.Graphics.TranslateTransform ( -this.Left, 
                                            -this.Top );
            clipping_rectangle = e.ClipRectangle;
            clipping_rectangle.Offset ( this.Left, this.Top );
            paint_event_args = new PaintEventArgs ( 
                                                e.Graphics, 
                                                clipping_rectangle );
                                        // paint container's 
                                        // background
            InvokePaintBackground ( this.Parent, paint_event_args );
                                        // paint container's 
                                        // foreground
            InvokePaint ( this.Parent, paint_event_args );
                                        // restore graphics to 
                                        // original state
            e.Graphics.EndContainer(state);
            }

        // *************************************************** OnPaint

        protected override void OnPaint ( PaintEventArgs e )
            {
            base.OnPaint ( e );

            make_control_backround_transparent ( e );

            if ( ( this.Height != ControlWidth ) ||
                 ( this.Width != ControlWidth ) )
                {
                revise_background_layer = true;
                ControlWidth = this.Width;
                update_geometry ( );
                this.Size = new Size ( ControlWidth, ControlWidth );
                }

            if ( ( background_layer == null ) || 
                   revise_background_layer )
                {
                create_background_layer ( );
                draw_background_layer ( );
                create_stationary_layer ( );
                draw_stationary_layer ( );
                revise_attitude_layers = true;
                revise_background_layer = false;
                }

            if ( revise_attitude_layers )
                {
                create_sky_ground_layer ( );
                draw_sky_ground_layer ( );
                create_pitch_layer ( );
                draw_pitch_layer ( );
                create_top_bottom_layer ( );
                draw_top_bottom_layer ( );
                create_roll_layer ( );
                draw_roll_layer ( );
                revise_attitude_layers = false;
                }
                                        // indicator layer is the only 
                                        // layer that is always drawn 
                                        // when either pitch or roll 
                                        // changes
            create_indicator_layer ( );
            draw_indicator_layer ( );

                                        // to change behavior, comment 
                                        // out the define of (at top)
                                        // DISPLAY_INDIVIDUAL_LAYERS
#if DISPLAY_INDIVIDUAL_LAYERS
                                        // following displays layers 
                                        // individually
            if ( display_layer [ "Background" ] )
                {
                background_layer.RenderGraphicsBuffer ( e.Graphics );
                }
            if ( display_layer [ "Indicator" ] )
                {
                indicator_layer.RenderGraphicsBuffer ( e.Graphics );
                }
            else
                {
                if ( display_layer [ "SkyGround" ] )
                    {
                    sky_ground_layer.RenderGraphicsBuffer ( 
                                         e.Graphics );
                    }
                if ( display_layer [ "Pitch" ] )
                    {
                    pitch_layer.RenderGraphicsBuffer ( 
                                    e.Graphics );
                    }
                if ( display_layer [ "TopBottom" ] )
                    {
                    top_bottom_layer.RenderGraphicsBuffer ( 
                                         e.Graphics );
                    }
                if ( display_layer [ "Roll" ] )
                    {
                    roll_layer.RenderGraphicsBuffer ( 
                                   e.Graphics );
                    }
                }
            if ( display_layer [ "Stationary" ] )
                {
                stationary_layer.RenderGraphicsBuffer ( e.Graphics );
                }
#else
                                        // following does not support 
                                        // the display of individual 
                                        // layers
            background_layer.RenderGraphicsBuffer ( e.Graphics );
            indicator_layer.RenderGraphicsBuffer ( e.Graphics );
            stationary_layer.RenderGraphicsBuffer ( e.Graphics );
#endif
            }

        } // class AttitudeIndicator

    // ************************************************ class TickMark 

    public class TickMark 
        {

        public enum Tick_Type 
            {
            LARGE_DIAMOND,
            SMALL_TICK,
            LARGE_TICK,
            SMALL_DIAMOND
            }

        int         degrees;
        Point       from;
        Tick_Type   tick_type;
        Point       to;

        // ************************************************** TickMark

        public TickMark ( int       degrees,
                          Point     from,
                          Point     to,
                          Tick_Type tick_type )
            {

            Degrees = degrees;
            From = from;
            To = to;
            TickType = tick_type;
            }

        // *************************************************** Degrees

        public int Degrees 
            {

            get
                {
                return ( degrees );
                }

            set
                {
                degrees = value;
                }
            }

        // ****************************************************** From

        public Point From
            {

            get
                {
                return ( from );
                }

            set
                {
                from = value;
                }
            }

        // ************************************************** TickType

        public Tick_Type TickType
            {

            get
                {
                return ( tick_type );
                }
            set
                {
                tick_type = value;
                }
            }

        // ******************************************************** To

        public Point To
            {

            get
                {
                return ( to );
                }

            set
                {
                to = value;
                }
            }

        } // class TickMark 

    } // namespace AttitudeIndicator
