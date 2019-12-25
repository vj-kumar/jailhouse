/*
 * Jailhouse, a Linux-based partitioning hypervisor
 *
 * Configuration for Pine64+ board, 2 GB
 *
 * Copyright (c) Vijai Kumar K, 2019
 *
 * Authors:
 *  Vijai Kumar K <vijaikumar.kanagarajan@gmail.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2.  See
 * the COPYING file in the top-level directory.
 */

#include <jailhouse/types.h>
#include <jailhouse/cell-config.h>

struct {
	struct jailhouse_system header;
	__u64 cpus[1];
	struct jailhouse_memory mem_regions[3];
	struct jailhouse_irqchip irqchips[1];
	struct jailhouse_pci_device pci_devices[1];
} __attribute__((packed)) config = {
	.header = {
		.signature = JAILHOUSE_SYSTEM_SIGNATURE,
		.revision = JAILHOUSE_CONFIG_REVISION,
		.flags = JAILHOUSE_SYS_VIRTUAL_DEBUG_CONSOLE,
		.hypervisor_memory = {
			.phys_start = 0xbc000000,
			.size = 0x4000000 - 0x100000, /* -1MB (PSCI) */
		},
		.debug_console = {
			.address = 0x01c28000,
			.size = 0x400,
			.type = JAILHOUSE_CON_TYPE_PL011,
			.flags = JAILHOUSE_CON_ACCESS_MMIO |
				 JAILHOUSE_CON_REGDIST_4,
		},
		.platform_info = {
			.arm = {
				.gic_version = 2,
				.gicd_base = 0x01c81000,
				.gicc_base = 0x01c82000,
				.gich_base = 0x01c84000,
				.gicv_base = 0x01c86000,
				.maintenance_irq = 25,
			},
		},
		.root_cell = {
			.name = "Pine64-Plus",

			.cpu_set_size = sizeof(config.cpus),
			.num_memory_regions = ARRAY_SIZE(config.mem_regions),
			.num_irqchips = ARRAY_SIZE(config.irqchips),
		},
	},

	.cpus = {
		0xff,
	},

	.mem_regions = {
                /* MMIO (permissive) */ {
                        .phys_start = 0x00000000,
                        .virt_start = 0x00000000,
                        .size =       0x40000000,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO,
                },
		/* RAM (permissive) */ {
			.phys_start = 0x40000000,
			.virt_start = 0x40000000,
			.size = 0x7c000000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_EXECUTE,
		},
		/* IVSHMEM shared memory region */ {
			.phys_start = 0xbbf00000,
			.virt_start = 0xbbf00000,
			.size = 0x100000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE,
		},
	},

	.irqchips = {
		/* GIC */ {
			.address = 0x01c81000,
			.pin_base = 32,
			.pin_bitmap = {
				0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
			},
		},
	},

	.pci_devices = {
		/* 0001:00:00.0 */ {
			.type = JAILHOUSE_PCI_TYPE_IVSHMEM,
			.domain = 1,
			.bdf = 0x00,
			.bar_mask = {
				0xffffff00, 0xffffffff, 0x00000000,
				0x00000000, 0x00000000, 0x00000000,
			},
			.shmem_region = 4,
			.shmem_protocol = JAILHOUSE_SHMEM_PROTO_VETH,
		},
	},
};
