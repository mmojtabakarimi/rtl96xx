#
# Makefile for the Linux networking core.
#

obj-y := sock.o request_sock.o skbuff.o iovec.o datagram.o stream.o scm.o \
	 gen_stats.o gen_estimator.o net_namespace.o

obj-$(CONFIG_SYSCTL) += sysctl_net_core.o
ifndef CONFIG_RTL8672
obj-$(CONFIG_HAS_DMA) += skb_dma_map.o
endif

obj-y		     += dev.o ethtool.o dev_mcast.o dst.o netevent.o \
			neighbour.o rtnetlink.o utils.o link_watch.o filter.o

obj-$(CONFIG_XFRM) += flow.o
obj-y += net-sysfs.o
obj-$(CONFIG_NET_PKTGEN) += pktgen.o
obj-$(CONFIG_NETPOLL) += netpoll.o
obj-$(CONFIG_NET_DMA) += user_dma.o
obj-$(CONFIG_FIB_RULES) += fib_rules.o
obj-$(CONFIG_TRACEPOINTS) += net-traces.o
obj-$(CONFIG_NET_DROP_MONITOR) += drop_monitor.o

EXTRA_CFLAGS += -I $(DIR_LINUX)/drivers/net/rtl86900/sdk/system/include/
EXTRA_CFLAGS += -I $(DIR_LINUX)/drivers/net/
EXTRA_CFLAGS += -I $(DIR_LINUX)/drivers/net/rtl86900/sdk/include/
EXTRA_CFLAGS += -I $(DIR_LINUX)/drivers/net/rtl86900/romeDriver/
