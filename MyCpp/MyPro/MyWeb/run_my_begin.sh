#!/bin/bash

set -e
cd $(dirname $0)
php $extension_dir -d extension=grpc.so -d max_execution_time=300 \
  BeginTask.php $1