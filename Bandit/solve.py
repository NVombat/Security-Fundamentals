import subprocess
import json
import glob

config_data = json.load(open("b1.json"))
#print(config_data)

proc = subprocess.run(['sshpass', '-p', config_data['password'],
'ssh', config_data['address'], '-p', config_data['port'], '-l', config_data['username']])

print(proc.returncode)

# output_pwd = subprocess.getoutput(config_data['commands'])
# print(output_pwd)
# output_path = subprocess.getoutput("pwd")
# print("PATH:", output_path)
# files = glob.glob(output_path+"/passwords.txt")

# if len(files)==0:
#     with open("passwords.txt", 'w') as pfile:
#         pfile.write("New Password New File\n")
# else:
#     with open("passwords.txt", 'a') as pfile:
#         pfile.write("New Password Old File\n")

# pfile.close()