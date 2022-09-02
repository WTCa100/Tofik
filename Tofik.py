import Checker_single
import Checker_Multiple
import Utilities
import sys


def give_help():
    print("Tofik is a .xlsx to .csv file converter.")
    print("In order to convert a file you have place them into \"xlsxRawFiles\".")
    print("After that you specify the mode you want to enter. The following program have 2 modes.")
    print("-s opt[file_name] \t-Single mode in which the program will only convert one selected file.")
    print("-m \t\t\t-Multiple mode in which the program will convert every program inside previously stated path.")


def single_mode(sysargs):
    if len(sysargs) >= 3:
        convert = Checker_single.Filer(sysargs[2])
        if convert.look_for_file():
            print("Converting...")
            converted = Utilities.MakeFile(sysargs[2])
            converted.actual_convert()
        else:
            return
    else:
        str_file_name = input("Please enter the name of the .xlsx file: ")
        convert = Checker_single.Filer(str_file_name)
        if convert.look_for_file():
            print("Converting...")
            converted = Utilities.MakeFile(str_file_name)
            converted.actual_convert()
        else:
            return
    print("Done!")
    return


def multi_mode():
    print(f"Do multiple files in directory")
    multi_files = Checker_Multiple.Filer_multi()
    multi_files.make_and_convert_file_list()
    return


def __main__():
    if len(sys.argv) < 2:
        print("Usage: py Tofik.py -mode")
        exit()
    elif '-s' in sys.argv:
        print("Single Mode")
        single_mode(sys.argv)
        exit()
    elif '-m' in sys.argv:
        print("Multi Mode")
        multi_mode()
        exit()
    elif '-h' in sys.argv:
        give_help()
        exit()
    elif "-meow" in sys.argv:
        print("Trivia: Program is named after my cat :3")
        exit()
    else:
        print(f"No such mode as {sys.argv[1]}. Type -h for help")
        exit()


if __name__ == "__main__":
    __main__()
