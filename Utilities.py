import pandas


class MakeFile:

    str_file_name = ""

    def __init__(self, xlsx_file_name):
        self.str_file_name = xlsx_file_name

    def actual_convert(self, path_in = ".\\xlsxRawFiles\\", path_out=".\\csvOutFiles\\"):
        csv_file_name = self.str_file_name[:self.str_file_name.find("xlsx")] + "csv"
        old_data = pandas.read_excel(path_in + self.str_file_name, index_col=None)
        old_data.to_csv(path_out + csv_file_name, encoding= 'utf-8')
