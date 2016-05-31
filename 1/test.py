#!/usr/bin/env python
import subprocess
import sys,os

# Unbuffered stdout.
sys.stdout = os.fdopen(sys.stdout.fileno(), 'w', 0)


passed = 0

n_tests = 2;

# Run a for loop of tests.
for i in range(1,n_tests+1):
    sys.stdout.write("Running test " + str(i) + "... ");
    # Run the version of testcirc$, redirect output into $.out
    subprocess.call("./testcirc" + str(i) + " > " + str(i) + ".out",shell=True)
    # Compare output to the ground truth.
    rt = subprocess.call("diff -b " + str(i) + ".out " + str(i) + ".er > /dev/null",shell=True);
    subprocess.call("rm " + str(i) + ".out",shell=True)
    if rt == 0:
        passed += 1
        sys.stdout.write("passed\n");
    else:
        sys.stdout.write("failed\n");




sys.stdout.write("Passed " + str(passed) + " of " + str(n_tests) + " tests.\n");