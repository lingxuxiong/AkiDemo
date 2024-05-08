export const add: (a: number, b: number) => number;
export const SayHello: (msg: string) => string;
export const callArkTSStaticMethod: (obj: object) => string;
export const asyncTaskReturnInt: () => Promise<number>;
export const asyncTaskReturnInt2: () => Promise<number>;

export class TaskRunner {
  TaskRunner();
  DoTask: () => Promise<number>
}