# Warning! This script deletes local git repo and starts anew.
# In the most cases it's probably not a good idea. Think twice before using it.
git config --global init.defaultBranch main
echo "$0: \033[0;31mWARNING!\033[0m This script will delete local git repo"
echo "$0: Press any key to continue"
read -k1
cd ..
echo "$0: Moved to root directory"
rm -rf .git
echo "$0: Deleted git repository"
git init
git remote add origin https://github.com/PrzemyslawSochon/cpp-vsc-clang-cmake-ninja
git fetch --all
git reset --hard origin/main
git pull --allow-unrelated-histories --force origin main
git add .
git commit -m 'Initial commit'
cd scripts
echo "$0: Moved back to scripts directory"
