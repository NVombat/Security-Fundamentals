import subprocess
import os

#Change permission of script to make script executable
os.chmod('script.sh', 0o755)

#Run the shell script in two ways:
#Using subprocess:
shell_output = subprocess.call("./script.sh", shell=True)
#Using os.system:
os.system("sh script.sh")

#To run a shell script with arguments
# arg = "some_argument"
# arg_output = subprocess.check_call("./script.sh '%s'" % arg, shell=True)

#Run some bash command
subprocess.run(["echo", "Hey Nikhill"])
#Run  bash command and access exit code
list_files = subprocess.run(["ls", "-l"])
print("The exit code was: %d" % list_files.returncode)
#Run a command and terminate if error occurs
subprocess.check_call(["ls", "-a", "-l"])