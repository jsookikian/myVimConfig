CONFIG_PATH=$(pwd)/"deepsea.vim"
VIM="jordan"
PLUGIN="plugin"
echo $CONFIG_PATH

cd $HOME
#
if [ ! -d $VIM ]
   then
      echo "~/$VIM does not exist"
      echo "creating $VIM directory"
      mkdir $VIM
   fi
cd $VIM
pwd

if [ ! -d $PLUGIN ]
   then
      echo "$PLUGIN directory does not exist"
      echo "creating $PLUGIN directory"
      mkdir $PLUGIN
   fi

cd $PLUGIN
pwd
cp $CONFIG_PATH . 
echo 
