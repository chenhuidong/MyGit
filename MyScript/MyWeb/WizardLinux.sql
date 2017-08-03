create table wizard_users(
m_id int auto_increment,
m_username varchar(256),
m_password varchar(256),
m_instance varchar(256),
primary key(m_id)
)

insert into wizard_users (m_username, m_password, m_instance) values ('chenhd', '222', 'chenhd');