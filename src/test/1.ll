; ModuleID = '1.cpp'
source_filename = "1.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@n = dso_local global i32 100, align 4
@m = dso_local global i32 0, align 4
@x = dso_local global float 5.000000e-01, align 4
@y = dso_local global float 0.000000e+00, align 4
@a = dso_local global [10 x i32] [i32 1, i32 2, i32 3, i32 4, i32 5, i32 0, i32 0, i32 0, i32 0, i32 0], align 16
@b = dso_local global [10 x i32] zeroinitializer, align 16
@c = dso_local global [2 x float] zeroinitializer, align 4
@d = dso_local global <{ float, float, [98 x float] }> <{ float 0x3FF3333340000000, float 0x400B333340000000, [98 x float] zeroinitializer }>, align 16

; Function Attrs: noinline nounwind optnone uwtable
define dso_local float @_Z4workifPA_A_iPA_f(i32 %0, float %1, i32* %2, float* %3) #0 {
  %5 = alloca i32, align 4
  %6 = alloca float, align 4
  %7 = alloca i32*, align 8
  %8 = alloca float*, align 8
  store i32 %0, i32* %5, align 4
  store float %1, float* %6, align 4
  store i32* %2, i32** %7, align 8
  store float* %3, float** %8, align 8
  %9 = load i32, i32* @n, align 4
  %10 = zext i32 %9 to i64
  %11 = load i32, i32* @n, align 4
  %12 = load i32, i32* getelementptr inbounds ([10 x i32], [10 x i32]* @a, i64 0, i64 0), align 16
  %13 = add nsw i32 %11, %12
  %14 = zext i32 %13 to i64
  %15 = load float*, float** %8, align 8
  %16 = mul nsw i64 1, %14
  %17 = getelementptr inbounds float, float* %15, i64 %16
  %18 = getelementptr inbounds float, float* %17, i64 1
  %19 = load float, float* %18, align 4
  ret float %19
}

; Function Attrs: noinline norecurse nounwind optnone uwtable
define dso_local i32 @main() #1 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  %2 = load float, float* @x, align 4
  %3 = fptosi float %2 to i32
  ret i32 %3
}

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { noinline norecurse nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 10.0.0-4ubuntu1 "}
