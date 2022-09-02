import re
import os


class Filer:

    str_file_name = ""

    def __init__(self, name_value):
        self.str_file_name = name_value

    def check_file_name(self):
        return re.search(".+\.xlsx", self.str_file_name)

    def look_for_file(self):
        print("Looking for file...", end=' ')
        if self.check_file_name() is None:
            print("The file is not .xlsx type!")
            return False
        else:
            str_file_path = os.path.abspath(os.getcwd()) + "\\xlsxRawFiles\\"
            if not os.path.exists(str_file_path + self.str_file_name):
                print(f"There is no such file in this directory! dir: {str_file_path}")
                return False
            return True
