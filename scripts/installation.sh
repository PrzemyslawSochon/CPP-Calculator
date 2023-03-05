echo "$0: \033[0;31mRun this script AFTER you build the project!\033[0m"
echo "$0: Press any key to continue"
read -k1
cd ../build
echo "$0: Changed to /build directory"
cmake --install .
echo "$0: Running installation"
export LD_LIBRARY_PATH="/usr/local/lib"
echo "$0: Setting local library path to usr/local/lib"
cd ../scripts
echo "$0: Returned to scripts folder"