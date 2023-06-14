import os
import shutil

for file in os.listdir():
	name, ext = os.path.splitext(file)
	print(name)
	if name == '17':
		print("name")
		for i in range(1,100):	
			value = int(name)
			newName = f"{value + i}{ext}"
			shutil.copyfile(file, newName)
