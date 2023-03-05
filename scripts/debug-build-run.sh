echo "$0: Thi script will build and run the project."
echo "$0: Press any key to continue"
read -k1
cd ../build
echo "$0: Changed to build directory"
rm -rf *
echo "$0: Removed all files from directory"
mkdir -p ../binary
set -x
cmake -DCPP_VERSION_TEST_CXX_STANDARD="20" -GNinja ../source
set +x
echo "$0: Running CMake with Ninja as build tool"
touch debug.log
ninja > debug.log
echo "$0: Running build, saving log to /build/debug.log"
cd ../binary
echo "$0: Changed to binary directory"
./Calculator
echo "$0: Running program from newly created binary folder"
cd ../scripts
echo "$0: Changed back to scripts folder"
