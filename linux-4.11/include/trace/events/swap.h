#undef TRACE_SYSTEM
#define TRACE_SYSTEM swap

#if !defined(_TRACE_SWAP_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_SWAP_H

#include <linux/tracepoint.h>
#include <linux/mm_types.h>

TRACE_EVENT(page_swap_in,

	TP_PROTO(unsigned long val, struct page *page),

	TP_ARGS(val, page),

	TP_STRUCT__entry(
		__field(unsigned long, val)
		__field(struct page*, page)
	),

	TP_fast_assign(
		__entry->val = val;
		__entry->page	= page;
	),

	/* Flag format is based on page-types.c formatting for pagemap */
	TP_printk("entry.val %lu page@[%p]",
			__entry->val, __entry->page)
);

TRACE_EVENT(page_swap_out,

	TP_PROTO(unsigned long val, struct page *page),

	TP_ARGS(val, page),

	TP_STRUCT__entry(
		__field(unsigned long, val)
		__field(struct page*, page)
	),

	TP_fast_assign(
		__entry->val = val;
		__entry->page	= page;
	),

	/* Flag format is based on page-types.c formatting for pagemap */
	TP_printk("entry.val %lu page@[%p]",
			__entry->val, __entry->page)
);
#endif /* _TRACE_SWAP_H */
#include <trace/define_trace.h>
