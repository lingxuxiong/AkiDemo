import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi, { TaskRunner } from 'libentry.so';

class ImageProcess {
  static foo(): string {
    return "this is foo"
  }
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            // hilog.info(0x0000, 'testTag', 'Test NAPI 2 + 3 = %{public}d', testNapi.add(2, 3));
            hilog.info(0x0000, 'testTag', 'SayHello type: %{public}s', typeof testNapi.SayHello);
            hilog.info(0x0000, 'testTag', 'SayHello response: %{public}s', testNapi.SayHello("hello world"));
            hilog.info(0x0000, 'testTag', 'callArkTSStaticMethod response: %{public}s', testNapi.CallArkTSStaticMethod(ImageProcess));

            testNapi.AsyncTaskReturnInt().then(res => {
              console.log('[AkiUI] AsyncTaskReturnInt: ' + res)
            });

            testNapi.AsyncTaskReturnInt2().then(res => {
              console.log('[AkiUI] AsyncTaskReturnInt2: ' + res)
            });

            let taskRunner: TaskRunner = new testNapi.TaskRunner();
            taskRunner.DoTask().then(res => {
              console.log('[AKI] DoTask: ' + res)
            });
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
