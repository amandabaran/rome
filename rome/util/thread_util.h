#pragma once

static inline void cpu_relax() { asm volatile("pause\n" ::: "memory"); }