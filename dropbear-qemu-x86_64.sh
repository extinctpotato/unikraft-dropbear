#!/bin/sh

kernel="build/unikraft-dropbear_qemu-x86_64"

qemu-system-x86_64 \
    -kernel "$kernel" \
    -m 128M \
    -netdev tap,id=en0,ifname=tap0,script=no,downscript=no \
    -device virtio-net-pci,netdev=en0 \
    -append "netdev.ipv4_addr=172.44.0.2 netdev.ipv4_gw_addr=172.44.0.1 netdev.ipv4_subnet_mask=255.255.255.0 -- cool" \
    -cpu max \
    -no-shutdown
