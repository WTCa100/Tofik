# Tofik
Tofik is a small and very simple `.xlsx` to `.csv` file converter that i deided to create in order to be able to quickly convert great ammount of .xlsx files into .csv
Generally I decided to create it for my personal usage only but if anyone wish to use it, just feel free to do it.

## Dependencies

Tofik converter is currently using the following external modules: `Pandas`, `Numpy`, `Pytz`, `Python-dateutil`, `Six`. </br>
You can use pip to download all of them via single command line.
```PowerShell
pip install pandas
```
In addition it is required to use `openpyxl` to use `-m` mode in Tofik. You can easliy download it via pip just like pandas.
```PowerShell
pip install openpyxl
```

# Converter

The entire project comes with few files as you may have seen.
- Tofik.py
- Utilities.py
- Checker_single|Checker_Multiple.py
- Tester.cpp and FileSpammer.exe (on release)

## Tofik.py
In order to use Tofik.py which is the actual converter, you will need to provide neccessery information to it.
```PowerShell
py Tofik.py -mode [optionally the name of the file with .xlsx extention]
```
The program containt 3 modes that can be accessed: <br>
<b> `-s`</b> - Single-mode that will only convert one selected by user file. Addictionally you can provide the file name after the single mode selection.
If no file name has been provided the program will prompt the user to input a valid .xlsx file later on. </br>
<b>Example usage:</b>
```PowerShell
py Tofik.py -s ConvertMe.xlsx
```

<b> `-m`</b> - Multi-mode that will only require no futher input,and will convert every file in /xlsxRawFiles directory. </br>
<b>Example Usage:</b>
```PowerShell
py Tofik.py -m
```
## Utilities.py and Checkers
These are the small modules that either validate files or convert provided files.</br>
<b>Utilities</b> - This program uses external module pandas and converts selected provided file.</br>
```Python
def actual_convert(self, path_in = ".\\xlsxRawFiles\\", path_out=".\\csvOutFiles\\"):
  csv_file_name = self.str_file_name[:self.str_file_name.find("xlsx")] + "csv"
  old_data = pandas.read_excel(path_in + self.str_file_name, index_col=None)
  old_data.to_csv(path_out + csv_file_name, encoding= 'utf-8')
```
<b>Checkers</b> - Checkers have usually the same functionality, it checks wether or not a file is eligible to be converted by checking it extention. The difference
between Single and Multiple mode is that the Checker_Multiple.py converts the set of files within it's class whereas Checker_Single didn't.
I decided to make such distinction since it was easier to get a head around the code and does not require to pass a big set of .xlsx objects.

# Troubleshooting or contact
If you encounter any type of problems in running the program please feel free to contact/start new issue.
