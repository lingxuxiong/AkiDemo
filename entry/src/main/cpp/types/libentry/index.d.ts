export const add: (a: number, b: number) => number;
export const SayHello: (msg: string) => string;
export const CallArkTSStaticMethod: (obj: object) => string;
export const AsyncTaskReturnInt: () => Promise<number>;
export const AsyncTaskReturnInt2: () => Promise<number>;

export class TaskRunner {
  TaskRunner();
  DoTask: () => Promise<number>
}