import subprocess
from pwn import *
import json
import glob

config_data = json.load(open("b1.json"))
#print(config_data)

#Use pwn to ssh into address and access password using commands
s = ssh(host=config_data['address'], port=config_data['port'],
user=config_data['username'], password=config_data['password'])
sh = s.process('/bin/sh')
pwd = s.process(config_data['commands']).recvall().decode()
print(pwd)

#Save to file
output_path = subprocess.getoutput("pwd")
print("PATH:", output_path)
files = glob.glob(output_path+"/passwords.txt")

if len(files)==0:
    with open("passwords.txt", 'w') as pfile:
        pfile.write("New Password New File\n")
else:
    with open("passwords.txt", 'a') as pfile:
        pfile.write("New Password Old File\n")

pfile.close()