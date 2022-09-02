import re
import os
import Utilities


class Filer_multi:
    str_xlsx_folder_path = ""

    def __init__(self, str_custom_path=".\\xlsxRawFiles\\"):
        self.str_xlsx_folder_path = str_custom_path

    def check_file(self, item):
        return re.search(".+\.xlsx", item)

    def make_and_convert_file_list(self):
        files_set = set(os.listdir(self.str_xlsx_folder_path))
        for item in files_set:
            print(f"Found {item}", end=" ")
            if not self.check_file(item):
                print("\nNot an .xlsx file, skipping")
                continue
            print("Converting...")
            converted_item = Utilities.MakeFile(item)
            converted_item.actual_convert()
            print(f"Successfully converted {item}")
        print("Files have been successfully converted!")
