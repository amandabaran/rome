IntegerFlagInfo = provider(fields = ["value"])

def _impl(ctx):
    return IntegerFlagProvider(value = int(ctx.build_setting))

int_flag(
    implementation = _impl,
    build_setting = config.int(flag = True),
)
