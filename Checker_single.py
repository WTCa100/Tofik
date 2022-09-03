import re
import os


class Filer:

    str_file_name = ""

    def __init__(self, name_value):
        self.str_file_name = name_value

    def check_file_name(self):
        index_last_dot = self.str_file_name.rfind(".")
        if index_last_dot == -1:
            return False
        str_act_ext = self.str_file_name[index_last_dot:]
        if re.search("\.xlsx", str_act_ext) is None:
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
