#!/bin/bash
echo $$ >> /sys/fs/cgroup/memory/cgroup.procs
sleep 1
# cgdelete -r -g cpuset,cpu,io,memory,hugetlb,pids,rdma,misc:/yuri
echo $$
if [ ! -d "/sys/fs/cgroup/memory/yuri/" ];then
	mkdir /sys/fs/cgroup/memory/yuri
else
	echo "cgroup yuri already exists"
fi

# echo "+memory" >> /sys/fs/cgroup/yuri/cgroup.subtree_control

#if [ ! -d "/sys/fs/cgroup/yuri/pagerank_150M/" ];then
	#mkdir /sys/fs/cgroup/yuri/pagerank_150M
#else
	#echo "cgroup yuri/pagerank_150M already exists"
#fi

echo 134217728 > /sys/fs/cgroup/memory/yuri/memory.limit_in_bytes
echo "set memory.limit_in_bytes to"
cat /sys/fs/cgroup/memory/yuri/memory.limit_in_bytes
echo "adding current shell to pagerank_150M"
#echo $$ >> /sys/fs/cgroup/yuri/pagerank_150M/cgroup.procs
