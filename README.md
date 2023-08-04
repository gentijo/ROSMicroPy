When switching between branches, you may need to delete the extra_packages/microros directory
then do a forced submodule recursive update.  Galactic has the code in the repo, Humble + will
link directly to the libMicroROS project.

if you get a package DL is missing, don't know ehy chalk it up to the microros build process being complicated.
cd to your device directory/build and execute rm -rf *; && cmake ..; && make;
