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
	struct jailhouse_memory mem_regions[35];
	struct jailhouse_irqchip irqchips[1];
	struct jailhouse_pci_device pci_devices[1];
} __attribute__((packed)) config = {
	.header = {
		.signature = JAILHOUSE_SYSTEM_SIGNATURE,
		.revision = JAILHOUSE_CONFIG_REVISION,
		.flags = JAILHOUSE_SYS_VIRTUAL_DEBUG_CONSOLE,
		.hypervisor_memory = {
			.phys_start = 0xbc000000,
			.size =       0x04000000,
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
			.num_pci_devices = ARRAY_SIZE(config.pci_devices),
			.num_irqchips = ARRAY_SIZE(config.irqchips),
		},
	},

	.cpus = {
		0xf,
	},

	.mem_regions = {
                /* SRAM */ {
                        .phys_start = 0x00018000,
                        .virt_start = 0x00018000,
                        .size =       0x00028000,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_EXECUTE,
                },
                /* Clock */ {
                        .phys_start = 0x01000000,
                        .virt_start = 0x01000000,
                        .size =       0x00100000,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO | JAILHOUSE_MEM_IO_32,
                },
                /* 1100000.mixer */ {
                        .phys_start = 0x01100000,
                        .virt_start = 0x01100000,
                        .size =       0x00100000,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO,
                },
                /* 1200000.mixer */ {
                        .phys_start = 0x01200000,
                        .virt_start = 0x01200000,
                        .size =       0x00100000,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO,
                },
                /* Syscon */ {
                        .phys_start = 0x01c00000,
                        .virt_start = 0x01c00000,
                        .size =       0x00001000,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO,
                },
                /* DMA */ {
                        .phys_start = 0x01c02000,
                        .virt_start = 0x01c02000,
                        .size =       0x00001000,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO,
                },
                /* LCD1 */ {
                        .phys_start = 0x01c0c000,
                        .virt_start = 0x01c0c000,
                        .size =       0x00001000,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO,
                },
                /* LCD2 */ {
                        .phys_start = 0x01c0d000,
                        .virt_start = 0x01c0d000,
                        .size =       0x00001000,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO,
                },
                /* MMC */ {
                        .phys_start = 0x01c0f000,
                        .virt_start = 0x01c0f000,
                        .size =       0x00001000,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO,
                },
                /* EEPROM */ {
                        .phys_start = 0x01c14000,
                        .virt_start = 0x01c14000,
                        .size =       0x00000400,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO,
                },
                /* USB */ {
                        .phys_start = 0x01c19000,
                        .virt_start = 0x01c19000,
                        .size =       0x00000400,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO,
                },
                /* USB */ {
                        .phys_start = 0x01c19400,
                        .virt_start = 0x01c19400,
                        .size =       0x00000014,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO,
                },
                /* USB */ {
                        .phys_start = 0x01c1a000,
                        .virt_start = 0x01c1a000,
                        .size =       0x00000100,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO,
                },
                /* USB */ {
                        .phys_start = 0x01c1a400,
                        .virt_start = 0x01c1a400,
                        .size =       0x00000100,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO,
                },
                /* USB */ {
                        .phys_start = 0x01c1a800,
                        .virt_start = 0x01c1a800,
                        .size =       0x00000100,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO,
                },
                /* USB */ {
                        .phys_start = 0x01c1b000,
                        .virt_start = 0x01c1b000,
                        .size =       0x00000100,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO,
                },
                /* USB */ {
                        .phys_start = 0x01c1b400,
                        .virt_start = 0x01c1b400,
                        .size =       0x00000100,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO,
                },
                /* USB */ {
                        .phys_start = 0x01c1b800,
                        .virt_start = 0x01c1b800,
                        .size =       0x00000004,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO,
                },
                /* Clock */ {
                        .phys_start = 0x01c20000,
                        .virt_start = 0x01c20000,
                        .size =       0x00000400,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO | JAILHOUSE_MEM_IO_32,
                },
                /* Pincontrol */ {
                        .phys_start = 0x01c20800,
                        .virt_start = 0x01c20800,
                        .size =       0x00000400,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO | JAILHOUSE_MEM_IO_32,
                },
                /* Watchdog */ {
                        .phys_start = 0x01c20ca0,
                        .virt_start = 0x01c20ca0,
                        .size =       0x00000020,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO | JAILHOUSE_MEM_IO_32,
                },
                /* UART */ {
                        .phys_start = 0x01c28000,
                        .virt_start = 0x01c28000,
                        .size =       0x00000020,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO | JAILHOUSE_MEM_IO_32,
                },
                /* I2C */ {
                        .phys_start = 0x01c2b000,
                        .virt_start = 0x01c2b000,
                        .size =       0x00000400,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO,
                },
                /* Ethernet */ {
                        .phys_start = 0x01c30000,
                        .virt_start = 0x01c30000,
                        .size =       0x00010000,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO,
                },
                /* GPU */ {
                        .phys_start = 0x01c40000,
                        .virt_start = 0x01c40000,
                        .size =       0x00010000,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO,
                },
                /* SRAM */ {
                        .phys_start = 0x01d00000,
                        .virt_start = 0x01d00000,
                        .size =       0x00040000,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_EXECUTE,
                },
                /* HDMI */ {
                        .phys_start = 0x01ee0000,
                        .virt_start = 0x01ee0000,
                        .size =       0x00010000,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO,
                },
                /* HDMI */ {
                        .phys_start = 0x01ef0000,
                        .virt_start = 0x01ef0000,
                        .size =       0x00010000,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO,
                },
                /* RTC */ {
                        .phys_start = 0x01f00000,
                        .virt_start = 0x01f00000,
                        .size =       0x00000400,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO | JAILHOUSE_MEM_IO_32,
                },
                /* Interrupt Controller */ {
                        .phys_start = 0x01f00c00,
                        .virt_start = 0x01f00c00,
                        .size =       0x00000400,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO | JAILHOUSE_MEM_IO_32,
                },
                /* Clock */ {
                        .phys_start = 0x01f01400,
                        .virt_start = 0x01f01400,
                        .size =       0x00000100,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO | JAILHOUSE_MEM_IO_32,
                },
                /* Pincontrol */ {
                        .phys_start = 0x01f02c00,
                        .virt_start = 0x01f02c00,
                        .size =       0x00000400,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO | JAILHOUSE_MEM_IO_32,
                },
                /* RSB(Reduced Serial Bus) */ {
                        .phys_start = 0x01f03400,
                        .virt_start = 0x01f03400,
                        .size =       0x00000400,
                        .flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
                                JAILHOUSE_MEM_IO,
                },
		/* System RAM */ {
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
			.shmem_region = 34,
			.shmem_protocol = JAILHOUSE_SHMEM_PROTO_VETH,
		},
	},
};
