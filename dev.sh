docker run --rm -ti $@ -w /tmp/work -v `pwd`/work:/tmp/work -v `pwd`/star-sw/StRoot:/tmp/star-sw-master/StRoot starbnl/star-sw:latest-build bash
