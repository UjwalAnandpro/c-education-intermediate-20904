import os
import sys
import subprocess

def main():
    if os.path.exists("c_education_intermediate.exe"):
        print("[INFO] Found compiled binary! Launching C Education Hub...")
        subprocess.run(["c_education_intermediate.exe"])
        return

    print("╔═══════════════════════════════════════════════════════════════════════╗")
    print("║               C INTERMEDIATE EDUCATION COURSE HUB                     ║")
    print("║        Interactive Deep Dive into Advanced C Programming              ║")
    print("╚═══════════════════════════════════════════════════════════════════════╝\n")
    print("Please compile the C project using GCC, Clang, or build.bat:")
    print("  gcc -Wall -Wextra -std=c99 -O2 src/*.c -o c_education_intermediate.exe")
    print("  .\\c_education_intermediate.exe\n")

if __name__ == '__main__':
    main()
