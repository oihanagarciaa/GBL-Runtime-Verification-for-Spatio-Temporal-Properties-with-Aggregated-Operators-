
/* auto-generated by gen_syscalls.py, don't edit */
#ifndef Z_INCLUDE_SYSCALLS_UART_H
#define Z_INCLUDE_SYSCALLS_UART_H


#include <tracing/tracing_syscall.h>

#ifndef _ASMLANGUAGE

#include <syscall_list.h>
#include <syscall.h>

#include <linker/sections.h>


#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#pragma GCC diagnostic push
#endif

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#if !defined(__XCC__)
#pragma GCC diagnostic ignored "-Warray-bounds"
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern int z_impl_uart_err_check(const struct device * dev);

__pinned_func
static inline int uart_err_check(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_UART_ERR_CHECK);
	}
#endif
	compiler_barrier();
	return z_impl_uart_err_check(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define uart_err_check(dev) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_UART_ERR_CHECK, uart_err_check, dev); 	retval = uart_err_check(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_UART_ERR_CHECK, uart_err_check, dev, retval); 	retval; })
#endif
#endif


extern int z_impl_uart_poll_in(const struct device * dev, unsigned char * p_char);

__pinned_func
static inline int uart_poll_in(const struct device * dev, unsigned char * p_char)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke2(*(uintptr_t *)&dev, *(uintptr_t *)&p_char, K_SYSCALL_UART_POLL_IN);
	}
#endif
	compiler_barrier();
	return z_impl_uart_poll_in(dev, p_char);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define uart_poll_in(dev, p_char) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_UART_POLL_IN, uart_poll_in, dev, p_char); 	retval = uart_poll_in(dev, p_char); 	sys_port_trace_syscall_exit(K_SYSCALL_UART_POLL_IN, uart_poll_in, dev, p_char, retval); 	retval; })
#endif
#endif


extern int z_impl_uart_poll_in_u16(const struct device * dev, uint16_t * p_u16);

__pinned_func
static inline int uart_poll_in_u16(const struct device * dev, uint16_t * p_u16)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke2(*(uintptr_t *)&dev, *(uintptr_t *)&p_u16, K_SYSCALL_UART_POLL_IN_U16);
	}
#endif
	compiler_barrier();
	return z_impl_uart_poll_in_u16(dev, p_u16);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define uart_poll_in_u16(dev, p_u16) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_UART_POLL_IN_U16, uart_poll_in_u16, dev, p_u16); 	retval = uart_poll_in_u16(dev, p_u16); 	sys_port_trace_syscall_exit(K_SYSCALL_UART_POLL_IN_U16, uart_poll_in_u16, dev, p_u16, retval); 	retval; })
#endif
#endif


extern void z_impl_uart_poll_out(const struct device * dev, unsigned char out_char);

__pinned_func
static inline void uart_poll_out(const struct device * dev, unsigned char out_char)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		arch_syscall_invoke2(*(uintptr_t *)&dev, *(uintptr_t *)&out_char, K_SYSCALL_UART_POLL_OUT);
		return;
	}
#endif
	compiler_barrier();
	z_impl_uart_poll_out(dev, out_char);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define uart_poll_out(dev, out_char) do { 	sys_port_trace_syscall_enter(K_SYSCALL_UART_POLL_OUT, uart_poll_out, dev, out_char); 	uart_poll_out(dev, out_char); 	sys_port_trace_syscall_exit(K_SYSCALL_UART_POLL_OUT, uart_poll_out, dev, out_char); } while(false)
#endif
#endif


extern void z_impl_uart_poll_out_u16(const struct device * dev, uint16_t out_u16);

__pinned_func
static inline void uart_poll_out_u16(const struct device * dev, uint16_t out_u16)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		arch_syscall_invoke2(*(uintptr_t *)&dev, *(uintptr_t *)&out_u16, K_SYSCALL_UART_POLL_OUT_U16);
		return;
	}
#endif
	compiler_barrier();
	z_impl_uart_poll_out_u16(dev, out_u16);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define uart_poll_out_u16(dev, out_u16) do { 	sys_port_trace_syscall_enter(K_SYSCALL_UART_POLL_OUT_U16, uart_poll_out_u16, dev, out_u16); 	uart_poll_out_u16(dev, out_u16); 	sys_port_trace_syscall_exit(K_SYSCALL_UART_POLL_OUT_U16, uart_poll_out_u16, dev, out_u16); } while(false)
#endif
#endif


extern int z_impl_uart_configure(const struct device * dev, const struct uart_config * cfg);

__pinned_func
static inline int uart_configure(const struct device * dev, const struct uart_config * cfg)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke2(*(uintptr_t *)&dev, *(uintptr_t *)&cfg, K_SYSCALL_UART_CONFIGURE);
	}
#endif
	compiler_barrier();
	return z_impl_uart_configure(dev, cfg);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define uart_configure(dev, cfg) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_UART_CONFIGURE, uart_configure, dev, cfg); 	retval = uart_configure(dev, cfg); 	sys_port_trace_syscall_exit(K_SYSCALL_UART_CONFIGURE, uart_configure, dev, cfg, retval); 	retval; })
#endif
#endif


extern int z_impl_uart_config_get(const struct device * dev, struct uart_config * cfg);

__pinned_func
static inline int uart_config_get(const struct device * dev, struct uart_config * cfg)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke2(*(uintptr_t *)&dev, *(uintptr_t *)&cfg, K_SYSCALL_UART_CONFIG_GET);
	}
#endif
	compiler_barrier();
	return z_impl_uart_config_get(dev, cfg);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define uart_config_get(dev, cfg) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_UART_CONFIG_GET, uart_config_get, dev, cfg); 	retval = uart_config_get(dev, cfg); 	sys_port_trace_syscall_exit(K_SYSCALL_UART_CONFIG_GET, uart_config_get, dev, cfg, retval); 	retval; })
#endif
#endif


extern void z_impl_uart_irq_tx_enable(const struct device * dev);

__pinned_func
static inline void uart_irq_tx_enable(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_UART_IRQ_TX_ENABLE);
		return;
	}
#endif
	compiler_barrier();
	z_impl_uart_irq_tx_enable(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define uart_irq_tx_enable(dev) do { 	sys_port_trace_syscall_enter(K_SYSCALL_UART_IRQ_TX_ENABLE, uart_irq_tx_enable, dev); 	uart_irq_tx_enable(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_UART_IRQ_TX_ENABLE, uart_irq_tx_enable, dev); } while(false)
#endif
#endif


extern void z_impl_uart_irq_tx_disable(const struct device * dev);

__pinned_func
static inline void uart_irq_tx_disable(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_UART_IRQ_TX_DISABLE);
		return;
	}
#endif
	compiler_barrier();
	z_impl_uart_irq_tx_disable(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define uart_irq_tx_disable(dev) do { 	sys_port_trace_syscall_enter(K_SYSCALL_UART_IRQ_TX_DISABLE, uart_irq_tx_disable, dev); 	uart_irq_tx_disable(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_UART_IRQ_TX_DISABLE, uart_irq_tx_disable, dev); } while(false)
#endif
#endif


extern void z_impl_uart_irq_rx_enable(const struct device * dev);

__pinned_func
static inline void uart_irq_rx_enable(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_UART_IRQ_RX_ENABLE);
		return;
	}
#endif
	compiler_barrier();
	z_impl_uart_irq_rx_enable(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define uart_irq_rx_enable(dev) do { 	sys_port_trace_syscall_enter(K_SYSCALL_UART_IRQ_RX_ENABLE, uart_irq_rx_enable, dev); 	uart_irq_rx_enable(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_UART_IRQ_RX_ENABLE, uart_irq_rx_enable, dev); } while(false)
#endif
#endif


extern void z_impl_uart_irq_rx_disable(const struct device * dev);

__pinned_func
static inline void uart_irq_rx_disable(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_UART_IRQ_RX_DISABLE);
		return;
	}
#endif
	compiler_barrier();
	z_impl_uart_irq_rx_disable(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define uart_irq_rx_disable(dev) do { 	sys_port_trace_syscall_enter(K_SYSCALL_UART_IRQ_RX_DISABLE, uart_irq_rx_disable, dev); 	uart_irq_rx_disable(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_UART_IRQ_RX_DISABLE, uart_irq_rx_disable, dev); } while(false)
#endif
#endif


extern void z_impl_uart_irq_err_enable(const struct device * dev);

__pinned_func
static inline void uart_irq_err_enable(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_UART_IRQ_ERR_ENABLE);
		return;
	}
#endif
	compiler_barrier();
	z_impl_uart_irq_err_enable(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define uart_irq_err_enable(dev) do { 	sys_port_trace_syscall_enter(K_SYSCALL_UART_IRQ_ERR_ENABLE, uart_irq_err_enable, dev); 	uart_irq_err_enable(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_UART_IRQ_ERR_ENABLE, uart_irq_err_enable, dev); } while(false)
#endif
#endif


extern void z_impl_uart_irq_err_disable(const struct device * dev);

__pinned_func
static inline void uart_irq_err_disable(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_UART_IRQ_ERR_DISABLE);
		return;
	}
#endif
	compiler_barrier();
	z_impl_uart_irq_err_disable(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define uart_irq_err_disable(dev) do { 	sys_port_trace_syscall_enter(K_SYSCALL_UART_IRQ_ERR_DISABLE, uart_irq_err_disable, dev); 	uart_irq_err_disable(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_UART_IRQ_ERR_DISABLE, uart_irq_err_disable, dev); } while(false)
#endif
#endif


extern int z_impl_uart_irq_is_pending(const struct device * dev);

__pinned_func
static inline int uart_irq_is_pending(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_UART_IRQ_IS_PENDING);
	}
#endif
	compiler_barrier();
	return z_impl_uart_irq_is_pending(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define uart_irq_is_pending(dev) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_UART_IRQ_IS_PENDING, uart_irq_is_pending, dev); 	retval = uart_irq_is_pending(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_UART_IRQ_IS_PENDING, uart_irq_is_pending, dev, retval); 	retval; })
#endif
#endif


extern int z_impl_uart_irq_update(const struct device * dev);

__pinned_func
static inline int uart_irq_update(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_UART_IRQ_UPDATE);
	}
#endif
	compiler_barrier();
	return z_impl_uart_irq_update(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define uart_irq_update(dev) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_UART_IRQ_UPDATE, uart_irq_update, dev); 	retval = uart_irq_update(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_UART_IRQ_UPDATE, uart_irq_update, dev, retval); 	retval; })
#endif
#endif


extern int z_impl_uart_tx(const struct device * dev, const uint8_t * buf, size_t len, int32_t timeout);

__pinned_func
static inline int uart_tx(const struct device * dev, const uint8_t * buf, size_t len, int32_t timeout)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke4(*(uintptr_t *)&dev, *(uintptr_t *)&buf, *(uintptr_t *)&len, *(uintptr_t *)&timeout, K_SYSCALL_UART_TX);
	}
#endif
	compiler_barrier();
	return z_impl_uart_tx(dev, buf, len, timeout);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define uart_tx(dev, buf, len, timeout) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_UART_TX, uart_tx, dev, buf, len, timeout); 	retval = uart_tx(dev, buf, len, timeout); 	sys_port_trace_syscall_exit(K_SYSCALL_UART_TX, uart_tx, dev, buf, len, timeout, retval); 	retval; })
#endif
#endif


extern int z_impl_uart_tx_u16(const struct device * dev, const uint16_t * buf, size_t len, int32_t timeout);

__pinned_func
static inline int uart_tx_u16(const struct device * dev, const uint16_t * buf, size_t len, int32_t timeout)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke4(*(uintptr_t *)&dev, *(uintptr_t *)&buf, *(uintptr_t *)&len, *(uintptr_t *)&timeout, K_SYSCALL_UART_TX_U16);
	}
#endif
	compiler_barrier();
	return z_impl_uart_tx_u16(dev, buf, len, timeout);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define uart_tx_u16(dev, buf, len, timeout) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_UART_TX_U16, uart_tx_u16, dev, buf, len, timeout); 	retval = uart_tx_u16(dev, buf, len, timeout); 	sys_port_trace_syscall_exit(K_SYSCALL_UART_TX_U16, uart_tx_u16, dev, buf, len, timeout, retval); 	retval; })
#endif
#endif


extern int z_impl_uart_tx_abort(const struct device * dev);

__pinned_func
static inline int uart_tx_abort(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_UART_TX_ABORT);
	}
#endif
	compiler_barrier();
	return z_impl_uart_tx_abort(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define uart_tx_abort(dev) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_UART_TX_ABORT, uart_tx_abort, dev); 	retval = uart_tx_abort(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_UART_TX_ABORT, uart_tx_abort, dev, retval); 	retval; })
#endif
#endif


extern int z_impl_uart_rx_enable(const struct device * dev, uint8_t * buf, size_t len, int32_t timeout);

__pinned_func
static inline int uart_rx_enable(const struct device * dev, uint8_t * buf, size_t len, int32_t timeout)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke4(*(uintptr_t *)&dev, *(uintptr_t *)&buf, *(uintptr_t *)&len, *(uintptr_t *)&timeout, K_SYSCALL_UART_RX_ENABLE);
	}
#endif
	compiler_barrier();
	return z_impl_uart_rx_enable(dev, buf, len, timeout);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define uart_rx_enable(dev, buf, len, timeout) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_UART_RX_ENABLE, uart_rx_enable, dev, buf, len, timeout); 	retval = uart_rx_enable(dev, buf, len, timeout); 	sys_port_trace_syscall_exit(K_SYSCALL_UART_RX_ENABLE, uart_rx_enable, dev, buf, len, timeout, retval); 	retval; })
#endif
#endif


extern int z_impl_uart_rx_enable_u16(const struct device * dev, uint16_t * buf, size_t len, int32_t timeout);

__pinned_func
static inline int uart_rx_enable_u16(const struct device * dev, uint16_t * buf, size_t len, int32_t timeout)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke4(*(uintptr_t *)&dev, *(uintptr_t *)&buf, *(uintptr_t *)&len, *(uintptr_t *)&timeout, K_SYSCALL_UART_RX_ENABLE_U16);
	}
#endif
	compiler_barrier();
	return z_impl_uart_rx_enable_u16(dev, buf, len, timeout);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define uart_rx_enable_u16(dev, buf, len, timeout) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_UART_RX_ENABLE_U16, uart_rx_enable_u16, dev, buf, len, timeout); 	retval = uart_rx_enable_u16(dev, buf, len, timeout); 	sys_port_trace_syscall_exit(K_SYSCALL_UART_RX_ENABLE_U16, uart_rx_enable_u16, dev, buf, len, timeout, retval); 	retval; })
#endif
#endif


extern int z_impl_uart_rx_disable(const struct device * dev);

__pinned_func
static inline int uart_rx_disable(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_UART_RX_DISABLE);
	}
#endif
	compiler_barrier();
	return z_impl_uart_rx_disable(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define uart_rx_disable(dev) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_UART_RX_DISABLE, uart_rx_disable, dev); 	retval = uart_rx_disable(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_UART_RX_DISABLE, uart_rx_disable, dev, retval); 	retval; })
#endif
#endif


extern int z_impl_uart_line_ctrl_set(const struct device * dev, uint32_t ctrl, uint32_t val);

__pinned_func
static inline int uart_line_ctrl_set(const struct device * dev, uint32_t ctrl, uint32_t val)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke3(*(uintptr_t *)&dev, *(uintptr_t *)&ctrl, *(uintptr_t *)&val, K_SYSCALL_UART_LINE_CTRL_SET);
	}
#endif
	compiler_barrier();
	return z_impl_uart_line_ctrl_set(dev, ctrl, val);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define uart_line_ctrl_set(dev, ctrl, val) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_UART_LINE_CTRL_SET, uart_line_ctrl_set, dev, ctrl, val); 	retval = uart_line_ctrl_set(dev, ctrl, val); 	sys_port_trace_syscall_exit(K_SYSCALL_UART_LINE_CTRL_SET, uart_line_ctrl_set, dev, ctrl, val, retval); 	retval; })
#endif
#endif


extern int z_impl_uart_line_ctrl_get(const struct device * dev, uint32_t ctrl, uint32_t * val);

__pinned_func
static inline int uart_line_ctrl_get(const struct device * dev, uint32_t ctrl, uint32_t * val)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke3(*(uintptr_t *)&dev, *(uintptr_t *)&ctrl, *(uintptr_t *)&val, K_SYSCALL_UART_LINE_CTRL_GET);
	}
#endif
	compiler_barrier();
	return z_impl_uart_line_ctrl_get(dev, ctrl, val);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define uart_line_ctrl_get(dev, ctrl, val) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_UART_LINE_CTRL_GET, uart_line_ctrl_get, dev, ctrl, val); 	retval = uart_line_ctrl_get(dev, ctrl, val); 	sys_port_trace_syscall_exit(K_SYSCALL_UART_LINE_CTRL_GET, uart_line_ctrl_get, dev, ctrl, val, retval); 	retval; })
#endif
#endif


extern int z_impl_uart_drv_cmd(const struct device * dev, uint32_t cmd, uint32_t p);

__pinned_func
static inline int uart_drv_cmd(const struct device * dev, uint32_t cmd, uint32_t p)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke3(*(uintptr_t *)&dev, *(uintptr_t *)&cmd, *(uintptr_t *)&p, K_SYSCALL_UART_DRV_CMD);
	}
#endif
	compiler_barrier();
	return z_impl_uart_drv_cmd(dev, cmd, p);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define uart_drv_cmd(dev, cmd, p) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_UART_DRV_CMD, uart_drv_cmd, dev, cmd, p); 	retval = uart_drv_cmd(dev, cmd, p); 	sys_port_trace_syscall_exit(K_SYSCALL_UART_DRV_CMD, uart_drv_cmd, dev, cmd, p, retval); 	retval; })
#endif
#endif


#ifdef __cplusplus
}
#endif

#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#pragma GCC diagnostic pop
#endif

#endif
#endif /* include guard */
