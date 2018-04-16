open Lwt;

module C = Cohttp_lwt_unix;

open Graphql_lwt;

type role =
  | User
  | Admin;

type user = {
  id: int,
  name: string,
  role,
  friends: list(user),
};

let rec alice = {id: 1, name: "Alice", role: Admin, friends: [bob]}
and bob = {id: 2, name: "Bob", role: User, friends: [alice]};

let user_role_values = [
  Schema.enum_value("USER", ~value=User),
  Schema.enum_value("ADMIN", ~value=Admin),
];

let user_role = Schema.enum("UserRole", ~values=user_role_values);

let user =
  Schema.obj("User", ~fields=user =>
    [
      Schema.field(
        "id", ~typ=Schema.non_null(Schema.int), ~args=[], ~resolve=((), p) =>
        p.id
      ),
      Schema.field(
        "name",
        ~typ=Schema.non_null(Schema.string),
        ~args=[],
        ~resolve=((), p) =>
        p.name
      ),
      Schema.field(
        "role", ~typ=Schema.non_null(user_role), ~args=[], ~resolve=((), p) =>
        p.role
      ),
      Schema.field(
        "friends",
        ~typ=Schema.non_null(Schema.list(Schema.non_null(user))),
        ~args=[],
        ~resolve=((), p) =>
        p.friends
      ),
    ]
  );

let schema =
  Schema.schema([
    Schema.io_field(
      "users",
      ~typ=Schema.non_null(Schema.list(Schema.non_null(user))),
      ~args=[],
      ~resolve=((), ()) =>
      Lwt.return([alice, bob])
    ),
  ]);

let () = Server.start(~ctx=() => (), schema) |> Lwt_main.run;