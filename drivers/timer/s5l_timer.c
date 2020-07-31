#include <clk.h>
#include <common.h>
#include <dm.h>
#include <timer.h>
#include <asm/io.h>
#include <linux/bitops.h>

//should actually define as a struct here..
#define TIMER64_TICKS_HIGH		0x2004
#define TIMER64_TICKS_LOW		0x2000

struct s5l_timer_priv {
	void __iomem *base;
};

static int s5l_timer_get_count(struct udevice *dev, u64 *count)
{
	struct s5l_timer_priv *priv = dev_get_priv(dev);
	u32 low, high;
	u64 timer;
	u32 old = readl(priv->base + TIMER64_TICKS_HIGH);

	while (1) {
		low = readl(priv->base + TIMER64_TICKS_LOW);
		high = readl(priv->base + TIMER64_TICKS_HIGH);
		if (old == high)
			break;
		else
			old = high;
	}
	timer = high;
	*count = (u64)((timer << 32) | low);

	return 0;
}

static int s5l_timer_probe(struct udevice *dev)
{
	struct timer_dev_priv *uc_priv = dev_get_uclass_priv(dev);
	struct s5l_timer_priv *priv = dev_get_priv(dev);
	struct clk clk;
	int ret;

	priv->base = dev_read_addr_ptr(dev);
	if (!priv->base)
		return -ENOENT;

//why this doesn't work?
#if 0
	ret = clk_get_by_index(dev, 0, &clk);
	if (ret)
		return ret;

	uc_priv->clock_rate = clk_get_rate(&clk);
	if (!uc_priv->clock_rate)
		return -EINVAL;

#endif

	uc_priv->clock_rate = 24000000;

	return 0;
}

static const struct timer_ops s5l_timer_ops = {
	.get_count = s5l_timer_get_count,
};

static const struct udevice_id s5l_timer_ids[] = {
	{ .compatible = "samsung,s5l8930-timer" },
	{ }
};

U_BOOT_DRIVER(s5l_timer) = {
	.name = "s5l_timer",
	.id = UCLASS_TIMER,
	.of_match = s5l_timer_ids,
	.priv_auto_alloc_size = sizeof(struct s5l_timer_priv),
	.probe = s5l_timer_probe,
	.ops = &s5l_timer_ops,
	.flags = DM_FLAG_PRE_RELOC,
};
