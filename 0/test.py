#!/usr/bin/env python
import subprocess
import sys,os

passed = 0

# Unbuffered stdout.
sys.stdout = os.fdopen(sys.stdout.fileno(), 'w', 0)


# Yes, these should be in a for loop.
# Run test 1
sys.stdout.write("Running test 1... ");
subprocess.call("./hello_world < 1.in > 1.out",shell=True)
rt = subprocess.call("diff -b 1.out 1.er",shell=True);
if rt == 0:
    passed += 1
    sys.stdout.write("passed\n");
else:
    sys.stdout.write("failed\n");

# Run test 2
sys.stdout.write("Running test 2... ")
subprocess.call("./hello_world < 2.in > 2.out",shell=True)
rt = subprocess.call("diff -b 2.out 2.er",shell=True);
if rt == 0:
    passed += 1
    sys.stdout.write("passed\n");
else:
    sys.stdout.write("failed\n");


sys.stdout.write("Passed " + str(passed) + " of 2 tests.\n");
