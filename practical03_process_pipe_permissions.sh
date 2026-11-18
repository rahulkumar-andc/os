#!/bin/bash
# ==============================================================================
# UNIVERSITY OF DELHI - OPERATING SYSTEMS PRACTICAL LAB (GE / PME)
# PRACTICAL 03
#
# QUESTION:
# Execute various LINUX commands for:
#   i. Process Control: fork, getpid, ps, kill, sleep
#  ii. Communication: Input-output redirection (> , >> , <), Pipe (|)
# iii. Protection Management: chmod, chown, chgrp
# ==============================================================================

echo "=== PART I: PROCESS CONTROL COMMANDS ==="
echo -n "[getpid equivalent] Shell PID: "
echo $$

echo "[ps] Listing current active processes:"
ps

echo "[sleep] Running sleep in background and verifying PID:"
sleep 10 &
SLEEP_PID=$!
echo "Background sleep started with PID: $SLEEP_PID"
ps -p $SLEEP_PID

echo "[kill] Terminating background sleep process:"
kill -9 $SLEEP_PID
echo "Process $SLEEP_PID terminated."

echo "=== PART II: COMMUNICATION (REDIRECTION & PIPES) ==="
echo "1. Redirection > (Overwrite):"
echo "First Line" > redirect_test.txt
cat redirect_test.txt

echo "2. Redirection >> (Append):"
echo "Second Line Added" >> redirect_test.txt
cat redirect_test.txt

echo "3. Pipe (|) and Word Count (wc -l):"
cat redirect_test.txt | wc -l

echo "=== PART III: PROTECTION MANAGEMENT (chmod, chown, chgrp) ==="
touch secure_file.txt
echo "Initial permissions:"
ls -l secure_file.txt

echo "[chmod] Changing permissions to 755 (rwxr-xr-x):"
chmod 755 secure_file.txt
ls -l secure_file.txt

echo "[chmod] Making file read-only (444):"
chmod 444 secure_file.txt
ls -l secure_file.txt

rm -f redirect_test.txt secure_file.txt
echo "Practical 03 Completed Successfully."
