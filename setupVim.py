from shutil import copy
import os

vim = ".vim"
plugin = "plugin"

home = os.path.expanduser("~")
deepsea = "deepsea.vim"
configPath = os.getcwd() + "/" + deepsea

#change directory to home directory
os.chdir(home)

#check if the .vim file exists. If it doesn't, create it.
if not os.path.isdir(vim):
   print (vim + " directory doesn't exist.")
   print ("creating " + vim + " directory.")
   os.mkdir(vim, 0755);

# change directories to .vim directory
os.chdir(vim);

# check if the plugin directory file exists. If it doesn't create it 
if not os.path.isdir(plugin):
   print (plugin + " directory doesn't exist.")
   print ("creating " + plugin + " directory.")
   os.mkdir(plugin, 0755);

os.chdir(plugin)
if not os.path.isfile(deepsea):
    print "Copying vim configuration..."
    copy(configPath, ".")

print ("Configuration setup complete")
