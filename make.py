#!/usr/bin/env python3

import licant

licant.execute("onboardtest.g.py")

licant.cxx_application("onboardtest-listener",
                       sources=["src/main.cpp"],
                       mdepends=["onboardtest"],
                       libs=["nos"])

licant.cxx_application("onboardtest-test",
                       sources=["tests/main.cpp"],
                       mdepends=["onboardtest"],
                       libs=["nos"])

licant.fileset("all", ["onboardtest-listener", "onboardtest-test"])

licant.ex("all")
