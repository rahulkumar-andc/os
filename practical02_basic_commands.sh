#!/bin/bash
# ==============================================================================
# UNIVERSITY OF DELHI - OPERATING SYSTEMS PRACTICAL LAB (GE / PME)
# PRACTICAL 02
#
# QUESTION:
# Execute various LINUX commands for:
#   i. Information Maintenance: wc, clear, cal, who, date, pwd
#  ii. File Management: cat, cp, rm, mv, cmp, comm, diff, find, grep, awk
# iii. Directory Management: cd, mkdir, rmdir, ls
# ==============================================================================

echo "=== PART I: INFORMATION MAINTENANCE COMMANDS ==="
echo -n "[pwd] Current Directory: "
pwd
echo -n "[date] Current Date & Time: "
date
echo "[who] Active Logged-in Users:"
who
echo "[cal] Calendar:"
cal

echo "=== PART II: FILE MANAGEMENT COMMANDS ==="
echo "Operating Systems Lab DU" > sample1.txt
echo "Operating Systems Practical File" > sample2.txt

echo "[cat] Content of sample1.txt:"
cat sample1.txt

echo "[cp] Copying sample1.txt to backup.txt"
cp sample1.txt backup.txt

echo "[mv] Renaming backup.txt to duplicate.txt"
mv backup.txt duplicate.txt

echo "[grep] Searching for 'Practical' in sample2.txt:"
grep "Practical" sample2.txt

echo "[wc] Word and Line Count of sample2.txt:"
wc sample2.txt

echo "[diff] Comparing sample1.txt and sample2.txt:"
diff sample1.txt sample2.txt || true

echo "[awk] Printing first word of sample1.txt:"
awk '{print $1}' sample1.txt

echo "=== PART III: DIRECTORY MANAGEMENT COMMANDS ==="
echo "[mkdir] Creating directory 'os_demo_dir'"
mkdir -p os_demo_dir

echo "[ls] Listing current directory contents:"
ls -lh

echo "[rmdir] Removing directory 'os_demo_dir'"
rmdir os_demo_dir

rm -f sample1.txt sample2.txt duplicate.txt
echo "Practical 02 Completed Successfully."
