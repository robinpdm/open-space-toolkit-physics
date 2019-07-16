#!/bin/bash

################################################################################################################################################################

# @project        Library ▸ Physics
# @file           tools/python/testing/docker/build.sh
# @author         Lucas Brémond <lucas@loftorbital.com>
# @license        Apache License 2.0

################################################################################################################################################################

set -a
set -e

script_directory="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
top_directory="${script_directory}/../../../.."

pushd "${top_directory}" > /dev/null

source "tools/python/testing/.env"

docker build \
--tag="${python_test_image_repository}:${python_test_image_tag}" \
--file="${script_directory}/Dockerfile" \
.

popd > /dev/null

################################################################################################################################################################
