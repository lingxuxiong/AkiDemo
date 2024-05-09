import { hilog } from '@kit.PerformanceAnalysisKit';
import akiTest from 'libentry.so';

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
            hilog.info(0x0000, 'testTag', 'Test NAPI 2 + 3 = %{public}d', akiTest.add(2, 3));
            hilog.info(0x0000, 'testTag', 'SayHello type: %{public}s', typeof akiTest.sayHello);
            hilog.info(0x0000, 'testTag', 'SayHello response: %{public}s', akiTest.sayHello("hello world"));
            hilog.info(0x0000, 'testTag', 'callArkTSStaticMethod response: %{public}s', akiTest.callArkTSStaticMethod(ImageProcess));

            akiTest.asyncTaskReturnInt().then(res => {
              console.log('[AkiUI] AsyncTaskReturnInt: ' + res)
            });

            let taskRunner = new akiTest.TaskRunner(500);
            taskRunner.time = 1000;
            hilog.info(0x0000, 'testTag', 'taskRunner.time = %{public}d', taskRunner.time);

            hilog.info(0x0000, 'testTag', 'before taskRunner.value = %{public}d', taskRunner.getValue());
            taskRunner.value = 1;
            hilog.info(0x0000, 'testTag', 'after taskRunner.value = %{public}d', taskRunner.getValue());

            taskRunner.doTask().then(res => {
              console.log('[AKI] DoTask: ' + res)
            });
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
