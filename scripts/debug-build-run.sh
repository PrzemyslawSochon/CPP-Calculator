mkdir -p ../build
cd ../build
echo "$0: Changed to build directory"
rm -rf *
echo "$0: Removed all files from directory"
set -x
cmake -DCPP_VERSION_TEST_CXX_STANDARD="20" -GNinja ../source
set +x
echo "$0: Running CMake"
touch debug.log
ninja > debug.log
echo "$0: Running build"
echo "$0: Log file was saved to /build/debug.log"
./Calculator
echo "$0: Running program"
cd ../scripts
echo "$0: Returned to scripts folder"
