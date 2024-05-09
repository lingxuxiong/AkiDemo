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

  export class TaskRunner {
    TaskRunner();
    doTask: () => Promise<number>
  }
}

export default akiTest;