import re
import os


class Filer:

    str_file_name = ""

    def __init__(self, name_value):
        self.str_file_name = name_value

    def check_file_name(self):
        indexLastDot = self.str_file_name.rfind(".")
        strActExt = self.str_file_name[indexLastDot:]
        if indexLastDot == -1 or re.search(strActExt, "\.xlsx") is None: # Yes it's overcomplicated
            return False
        return True

    def look_for_file(self):
        if not self.check_file_name():
            print("The file is not .xlsx type!")
            return False
        else:
            print("Looking for file...", end=' ')
            str_file_path = os.path.abspath(os.getcwd()) + "\\xlsxRawFiles\\"
            if not os.path.exists(str_file_path + self.str_file_name):
                print(f"There is no such file in this directory! dir: {str_file_path}")
                return False
            return True
