#!/bin/bash

grep "Version"  ../rpmbuild/SPECS/concur_c.spec | awk '{print $2}'