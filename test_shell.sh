#!/bin/bash

# === Simple Shell Test Script ===

BINARY=./shell
PASS=0
FAIL=0

print_result() {
  if [ $1 -eq 0 ]; then
    echo -e "[✔] $2"
    PASS=$((PASS+1))
  else
    echo -e "[✘] $2"
    FAIL=$((FAIL+1))
  fi
}

# Test 1: /bin/ls
echo "/bin/ls" | $BINARY >/dev/null 2>&1
print_result $? "Executes /bin/ls"

# Test 2: ls via PATH
echo "ls" | $BINARY >/dev/null 2>&1
print_result $? "Executes ls using PATH"

# Test 3: command not found
echo "nonexistentcmd" | $BINARY >/dev/null 2>&1
test $? -eq 127
print_result $? "Returns 127 for command not found"

# Test 4: empty input
echo "" | $BINARY >/dev/null 2>&1
print_result $? "Handles empty input correctly"

# Test 5: PATH empty
env -i PATH= $BINARY << EOF 2>&1 | grep -q "ls: not found"
ls
EOF
print_result $? "Fails gracefully with empty PATH"

# Test 6: echo command
echo "echo Hello Shell" | $BINARY | grep -q "Hello Shell"
print_result $? "Executes echo with arguments"

# Test 7: exit with status
(echo "exit 42") | $BINARY
STATUS=$?
test $STATUS -eq 42
print_result $? "Exits with provided status code"

# Test 8: exit uses last_status
(echo "nonexistentcmd"; echo "exit") | $BINARY
STATUS=$?
test $STATUS -eq 127
print_result $? "Exit uses last command status"

# Test 9: cd to /tmp
echo "cd /tmp" | $BINARY
echo "pwd" | $BINARY | grep -q "/tmp"
print_result $? "Handles built-in cd"

# Test 10: multiple commands
(echo "ls"; echo "pwd"; echo "whoami") | $BINARY >/dev/null 2>&1
print_result $? "Handles multiple commands in sequence"

# === Summary ===
echo ""
echo "Passed: $PASS"
echo "Failed: $FAIL"
