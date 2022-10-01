#!/usr/bin/env python3

import licant

licant.cxx_application("target",
                       sources=["src/main.cpp"],
                       libs=["nos"])

licant.ex("target")
