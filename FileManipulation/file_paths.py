#Import libraries
from pathlib import Path
import subprocess
import sys
import os

#Prints the systems operating system
print(sys.platform)

#Prints a method to create a path
print(Path('folderX') / 'folderY' / 'folderZ' / 'fileABC')

#Prints current working directory
print(Path.cwd())
#Switches directories
os.chdir("/home/nvombat/Desktop")
#Prints current working directory
print(Path.cwd())
#Checks to see if we can run commands on that directory
subprocess.run(["ls"])

#Prints the path of the home directory of the user
print(Path.home())

#Creates a directory in the mentioned path
#os.makedirs("/home/nvombat/Desktop/Security-Fundamentals/FileManipulation/TestDir1")
#Path("/home/nvombat/Desktop/Security-Fundamentals/FileManipulation/TestDir2").mkdir()

#Returns true if the path is absolute and false if its relative
print(Path.cwd().is_absolute())
print(os.path.isabs(Path.cwd()))

#Returns the value of the absolute path of any relative variable
print(os.path.abspath("file_ops.py"))

#Returns the value of the relative path
print(os.path.relpath("/Desktop", "file_ops.py"))

#Prints the different parts of a path using the Path object
p = Path("/home/nvombat/Desktop/Security-Fundamentals/FileManipulation/script.sh")
print("ANCHOR:", p.anchor)
print("NAME:", p.name)
print("PARENT:", p.parent)
print("STEM:", p.stem)
print("SUFFIX:", p.suffix)
print("DRIVE:", p.drive)

#Prints the different parent directories in a path using Path object
print(Path.cwd())
print(Path.cwd().parents[0])
print(Path.cwd().parents[1])
print(Path.cwd().parents[2])

#Prints the base name of the file and the directory using the os module
print(os.path.dirname(p))
print(os.path.basename(p))

#Returns a tuple of the base name and the directory
print(os.path.split(p))

#Returns a list of the various parts of the path
path = "/home/nvombat/Desktop/Security-Fundamentals/FileManipulation/script.sh"
print(path.split(os.sep))

#Returns the size of a file or folder
print(os.path.getsize("/home/nvombat/Desktop/Security-Fundamentals/FileManipulation/script.sh"))
#Returns the contents of a folder in a list
print(os.listdir("/home/nvombat/Desktop"))

#Joins paths using os.path.join and then gets size of that file
filename = "script.sh"
print(os.path.getsize(os.path.join("/home/nvombat/Desktop/Security-Fundamentals/FileManipulation", filename)))

check_path_file = Path("/home/nvombat/Desktop/Security-Fundamentals/FileManipulation/script.sh")
check_path_dir = Path("/home/nvombat/Desktop/Security-Fundamentals/FileManipulation/Test")

#Checks if files and directories exists and whether they are files or directories
print(check_path_file.exists())
print(check_path_file.is_file())
print(check_path_dir.is_dir())
print(check_path_dir.exists())