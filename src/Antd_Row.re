module AntRow = {
  [@bs.module "antd"] [@react.component]
  external make:
    (~align: 'a, ~gutter: 'b, ~justify: 'c, ~_type: 'd, ~children: 'e) =>
    React.element =
    "Row";
};

[@bs.deriving jsConverter]
type justify = [
  | `start
  | [@bs.as "end"] `end_
  | `center
  | [@bs.as "space-around"] `space_around
  | [@bs.as "space-between"] `space_between
];

[@react.component]
let make =
    (
      ~align: [@bs.string] [ | `top | `middle | `bottom]=?,
      ~gutter: Js.t({..})=?,
      ~justify=?,
      ~_type: string=?,
      ~children: React.element=?,
    ) =>
  <AntRow
    align
    gutter
    justify={
      switch (justify) {
      | None => ""
      | Some(x) => justifyToJs(x)
      }
    }
    _type>
    children
  </AntRow>;
