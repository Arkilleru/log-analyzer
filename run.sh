#!/bin/bash

BUILD_DIR="build"
TARGET="log-analyzer-cli"

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

print_info() {
    echo -e "${BLUE} $1${NC}"
}

print_success() {
    echo -e "${GREEN} $1${NC}"
}

print_warning() {
    echo -e "${YELLOW} $1${NC}"
}

print_error() {
    echo -e "${RED} $1${NC}"
}

build_project() {
    print_info "Building Log Analyzer..."
    mkdir -p $BUILD_DIR
    cd $BUILD_DIR
    cmake -DCMAKE_BUILD_TYPE=Release ..
    make -j$(nproc)
    cd ..
    print_success "Build complete!"
}

run_cli() {
    print_info "Running Log Analyzer..."
    
    if [ ! -d "$BUILD_DIR" ]; then
        build_project
    fi
    
    cd $BUILD_DIR/cli
    ./$TARGET
}

run_tests() {
    print_info "Running tests..."
    if [ ! -d "$BUILD_DIR" ]; then
        build_project
    fi
    cd build/tests
    ./test-runner
    print_success "All tests passed!"
    cd ../..
}

clean_project() {
    print_warning "Cleaning build directory..."
    rm -rf $BUILD_DIR
    print_success "Clean complete!"
}

run_all() {
    print_info "Starting full pipeline..."
    clean_project
    build_project
    run_tests
}

case "$1" in
    "build")
        build_project
        ;;
    "test")
        run_tests
        ;;
    "clean")
        clean_project
        ;;
    "all")
        run_all
        ;;
    "cli")
        run_cli
        ;;
    *)
        print_error "Unknown command: $1"
        exit 1
        ;;
esac