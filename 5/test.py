#!/usr/bin/env python
import subprocess

passed = 0

n_tests = 4;

# Run a for loop of tests.
for i in ["add", "sub", "mult", "div"]:
    print "Running test " + str(i) + "... "
    # Run the version of test_$, redirect output into $.out
    subprocess.call("./test_" + i + " > " + i + ".out",shell=True)
    # Compare output to the ground truth.
    rt = subprocess.call("diff -b " + i + ".out " + i + ".er > /dev/null",shell=True);
    subprocess.call("rm " + i + ".out",shell=True)
    if rt == 0:
        passed += 1
        print "passed"
    else:
        print "failed"




print "Passed " + str(passed) + " of " + str(n_tests) + " tests"
