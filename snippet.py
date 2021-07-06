# INSTRUCTIONS: run this code with "python3 snippetGen.py > out.txt" in the root folder
# of Leones000 it will search over all "imprimibles" folder and parse all cpp codes into json.
# Do cmd+shift+p or equivalent and go to "Preferences: Configure User Snippets" then look for "cpp.json"
# copy and paste contents from out.txt to cpp.json

import os
rootdir = '/Users/crystalrodriguez/Documents/ICPC/Codes'
ans = "{\n"
temp = "\"%s\": {\n\t\"prefix\": \"%s\" ,\n\t\"body\": %s\n},\n"
for subdir, dirs, files in os.walk(rootdir):
  for file in files:
    rootSubFile = os.path.join(subdir, file);
    # print(rootSubFile)
    # continue
    if file.endswith("cpp"):
        # print(rootSubFile)
        with open(rootSubFile) as f:
            lines = f.readlines()
            lines2 = "["
            for i in lines:
                lines2 += "\"" + i.rstrip().replace("\"", "\\\"") + "\","
            lines2 += "]"
            ans = ans + (temp % (file, file, lines2))
ans += "}"
print(ans)