/**
 * Aki Test Module
 * @since 1.0
 * @sysCap 系统能力
 * @devices 支持设备
 * @import 导入模块
 * @permission 权限列表
 */
declare namespace akiTest {
  function add(a: number, b: number): number
  function sayHello(msg: string): string;
  function callArkTSStaticMethod(obj: object): string;
  function asyncTaskReturnInt(): Promise<number>;

  class TaskRunner {
    constructor();
    constructor(num: number);

    doTask: () => Promise<number>;

    getValue: () => number;

    value: number;
    time: number;
    state: TaskState;
  }

  enum TaskState {
    INITIALIZED,
    STARTED,
    STOPPED,
    FINISHED,
  }

  class JSBind {
    static bindFunction(name: string, func: Function): string;
  }

}

export default akiTest;