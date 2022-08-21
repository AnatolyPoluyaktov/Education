from .Factories import CounterFactory
from .Factories import UserFactory
from rest_framework.test import APIClient
import pytest


@pytest.mark.django_db
def test_view():
    client = APIClient()
    user = UserFactory(username="Alan",
                       email="a.lan", password='1')
    counter = CounterFactory(user=user)
    client.force_authenticate(user=user)
    response = client.get('/count/')
    assert response.data == 0

    response = client.post('/count/')
    assert response.data == 'ok'

    response = client.get('/count/')
    assert response.data == 1

    response = client.post('/count/')
    assert response.data == 'ok'

    response = client.get('/count/')
    assert response.data == 2

    response = client.delete('/count/')
    assert response.data == 'ok'

    response = client.get('/count/')
    assert response.data == 1

    response = client.delete('/count/')
    assert response.data == 'ok'

    response = client.get('/count/')
    assert response.data == 0

    response = client.delete('/count/')
    assert response.data == 'ok'

    response = client.get('/count/')
    assert response.data == 0
